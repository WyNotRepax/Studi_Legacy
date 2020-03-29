/* 
 Beispiel einfacher UDP Echo-Server 
 Aus Stevens: Unix Network Programming 
 CWe 10/2016: adaptiert fuer Ubuntu 16.04 64Bit
*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SRV_PORT 8998
#define MAX_SOCK 10
#define MAXLINE 512

// Vorwaertsdeklarationen
void dg_echo(int); 
void err_abort(char *str);

// Explizite Deklaration zur Vermeidung von Warnungen
void exit(int code);
void *memset(void *s, int c, size_t n);

int main(int argc, char *argv[]) {

	// Deskriptor
	int sockfd;

	// Socket Adresse
	struct sockaddr_in srv_addr;

	// TCP-Socket erzeugen
	if((sockfd=socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		err_abort("Kann Stream-Socket nicht oeffnen!");
	}

	// Binden der lokalen Adresse damit Clients uns erreichen
	memset((void *)&srv_addr, '\0', sizeof(srv_addr));
	srv_addr.sin_family = AF_INET;
	srv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	srv_addr.sin_port = htons(SRV_PORT);
	if( bind(sockfd, (struct sockaddr *)&srv_addr,
		sizeof(srv_addr)) < 0 ) {
		err_abort("Kann lokale Adresse nicht binden, laeuft fremder Server?");
	}

	printf("UPD Echo-Server: bereit ...\n");
	dg_echo(sockfd);
} 

/* 
dg_echo: Lesen von Daten vom Socket und an den Client zuruecksenden 
*/
void dg_echo(int sockfd) {
	int alen, n;
	char in[MAXLINE], out[MAXLINE+6];
	struct sockaddr_in cli_addr;

	for(;;) {
		alen = sizeof(cli_addr);
		memset((void *)&in,'\0',sizeof(in));

		// Daten vom Socket lesen
		n = recvfrom(sockfd, in, MAXLINE, 0, (struct sockaddr *)&cli_addr, &alen);
		if( n<0 ) {
			err_abort("Fehler beim Lesen des Sockets!");	
		}
		sprintf(out,"Echo: %s",in);

		// Daten schreiben
		if(sendto(sockfd, out, n+6, 0, (struct sockaddr *)&cli_addr, alen)!=n+6){
			err_abort("Fehler beim Schreiben des Sockets!");
		}
        }
}


/*
Ausgabe von Fehlermeldungen
*/
void err_abort(char *str){
	fprintf(stderr,"UDP Echo-Server: %s\n",str);
	fflush(stdout);
	fflush(stderr);
	exit(1);
}
