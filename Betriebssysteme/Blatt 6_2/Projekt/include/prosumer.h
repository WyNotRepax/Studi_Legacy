//
// Created by bsteinka on 15.11.19.
//

#ifndef PROJEKT_PROSUMER_H
#define PROJEKT_PROSUMER_H

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


#define QUEUESIZE 10
#define LOOP 20

void *producer (void *args);
void *consumer (void *args);

typedef struct {
    char* buf[QUEUESIZE];
    long head, tail;
    int full, empty;
    pthread_mutex_t *mut;
    pthread_cond_t *notFull, *notEmpty;
} queue;

queue *queueInit (void);
void queueDelete (queue *q);
void queueAdd (queue *q, char* in);
void queueDel (queue *q, char* *out);

#endif //PROJEKT_PROSUMER_H
