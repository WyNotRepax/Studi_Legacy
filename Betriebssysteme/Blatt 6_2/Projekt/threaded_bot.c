#include <malloc.h>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <sys/time.h>

#include <pthread.h>
#include <prosumer.h>

#include "web_request.h"

#define USE_PROXY 0
#define MAX_THREADS 10

int DONE = 0;

void *producer(void*);
void *consumer(void*);

typedef struct URLList {
    char* url;
    struct URLList* next;
} URLList;

typedef struct{
    URLList* urlList;
    queue* q;
    int j;
    int *counter;
    pthread_mutex_t* mut;
} data;




data *initData(URLList* urlList, queue* q, int j, int* counter, pthread_mutex_t* mut){
    data* d;
    d = (data *)malloc(sizeof(data));
    if(d == NULL) return NULL;
    d->urlList = urlList;
    d->q = q;
    d->j = j;
    d->counter=counter;
    d->mut=mut;
    return d;
}


/* 
 * Main
 */
int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr,
                "Usage: %s <inputfile> [options]\n\n"
                "Options:\n"
                "\t--webreq-delay <uint>\n"
                "\t--webreq-delay-seed <int>\n"
                "\t--webreq-path <path>\n",
                argv[0]);
        return EXIT_FAILURE;
    }

    // open file containing the pages to GET
    FILE* fd_in;
    if (!(fd_in = fopen(argv[1], "r"))) {
        perror("failed to open input file");
        exit(EXIT_FAILURE);
    }

    // generate time stamp
    struct timeval  tv;

    gettimeofday(&tv, NULL);
    double start = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;

    //-------------------------------------------------------------

    // create list of URLs to query
    URLList* urllist = NULL;
    URLList* curr = NULL;

    char url[256];

    while (fgets(url, sizeof (url), fd_in)) {
        // trim newline chars and skip empty lines
        // (strtok: no token found -> NULL -> empty string)
        if (strtok(url, "\r\n") == NULL)
            continue;

        // append the url to the list
        if (urllist == NULL) {
            // start of the list
            urllist = malloc(sizeof (URLList));
            curr = urllist;
        } else {
            // new node in list
            curr->next = malloc(sizeof (URLList));
            curr = curr->next;
        }

        curr->url = strdup(url);
        curr->next = NULL;
    }

    // close file
    fclose(fd_in);

    // init lib
    webreq_init(argc, argv);

    // Queue erzeugen
    queue* q;
    q = queueInit();
    if(q == NULL){
        fprintf(stderr,"Error Creating Queue!");
        exit(EXIT_FAILURE);
    }

    // Data erzeugen

    data* data_producer;
    data_producer = initData(urllist,q,0,NULL,NULL);


    // Producer erzeugen
    pthread_t prod;
    pthread_create(&prod,NULL,&producer,data_producer);

    // Consumer erzeugen
    pthread_t threads[MAX_THREADS];
    /* MAX_THREADS erzeugen */
    int counter = 0;
    pthread_mutex_t counter_mut;
    pthread_mutex_init(&counter_mut, NULL);

    data* d;
    for (int i = 0; i < MAX_THREADS; i++) {
        d = initData(NULL,q,i+1,&counter,&counter_mut);
        pthread_create(&threads[i],NULL,consumer,d);
    }


    printf("Warte auf Producer...\n");
    pthread_join(prod,EXIT_SUCCESS);
    printf("Producer Fertig!\n");
    for (int i = 0; i < MAX_THREADS; i++) {
        printf("Warte auf Thread %i\n",i+1);
        pthread_join(threads[i],EXIT_SUCCESS);
    }

    // free mem
    webreq_cleanup();

    curr = urllist;
    URLList* next;

    // free list from first to last element
    while (curr != NULL) {
        // save ptr to next node, so that this node can be freed
        next = curr->next;
        free(curr->url);
        free(curr);
        curr = next;
    }

    //-------------------------------------------------------------
    // measure runtime
    gettimeofday(&tv, NULL);
    double end = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
    double diff = (end - start) / 1000;

    printf("Duration: %5.2f s\n", diff);

    return EXIT_SUCCESS;
}



void *producer(void *pVoid){
    data *d;
    d = (data *) pVoid;
    queue *q;
    q = d->q;
    URLList* urlList;
    urlList = d->urlList;
    URLList* curr = urlList;
    while(curr != NULL){
        pthread_mutex_lock(q->mut);
        if(q->full){
            printf("Queue is Full; Waiting!\n");
            pthread_cond_wait(q->notFull,q->mut);
        }
        queueAdd(q,curr->url);
        pthread_mutex_unlock(q->mut);
        pthread_cond_signal(q->notEmpty);
        curr = curr->next;
    }
    DONE = 1;
    printf("Done set!\n");
    return EXIT_SUCCESS;
}

void *consumer(void *pVoid){
    data* d;
    d = (data *)pVoid;
    printf("%i gestartet\n",d->j);
    queue* q = d->q;
    while(1){
        pthread_mutex_lock(q->mut);
        if(q->empty){
            if(DONE){
                pthread_mutex_unlock(q->mut);
                printf("Thread %i beendet!\n",d->j);
                return EXIT_SUCCESS;
            }
            printf("Queue is Empty; Waiting!\n");
            pthread_cond_wait(q->notEmpty,q->mut);
        }
        char* curr;
        queueDel(q,&curr);
        pthread_mutex_unlock(q->mut);
        pthread_cond_signal(q->notFull);

        pthread_mutex_lock(d->mut);
        (*d->counter)++;
        int i = *(d->counter);
        pthread_mutex_unlock(d->mut);

        char* url = strdup(curr);
        strtok(url, "/");
        char* domain = strtok(NULL, "/");

        if (domain == NULL) {
            fprintf(stderr, "[ERROR] domain could not be extracted from URL [%s], skipping\n", curr);
        } else {
            char filename[64];
            snprintf(filename, sizeof (filename), "%i_%i_%s.html", i,d->j, domain);

            printf("%i:[START] Downloading URL: %s ->> File: %s\n",d->j ,curr, filename);

            int res;
#if USE_PROXY
            res = webreq_download_via_proxy(curr->url, filename);
#else
            res = webreq_download(curr, filename);
#endif
            if (res < 0)
                fprintf(stderr, "[ERROR] URL: %s, Message: %s\n", curr, webreq_error(res));
            else if (res != WEBREQ_HTTP_OK)
                fprintf(stderr, "[ERROR] HTTP Status %d returned for URL: %s\n", res, curr);
            else
                printf("%i:[DONE ] URL: %s ->> File: %s\n",d->j, curr, filename);
        }
        free(url);
    }

}
