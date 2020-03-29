/*
 * Beispiel check_host.c: 
 * Benutzung der Systemfunktion gethostbyname()
 * getestet unter Ubuntu 14.04 32Bit
 */

#include <stdio.h>
#include <sys/types.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
	char *ptr;
	struct hostent *hptr; /* fuer gethostbyname */
	struct in_addr *aptr; /* fuer IP Adressen */
	while(--argc > 0 ) { /* Schleife uber alle Argumente */
		/* naechstes Argument, z.B. lbst-npca-1.lbst.ecs... */
		ptr = *++argv; /* gethostbyname aufrufen */
		if( (hptr = gethostbyname(ptr)) == NULL ) {
		fprintf(stderr, "gethostbyname fails for %s\n", ptr);
		/* naechstes Argument */
		continue; 
	}
	printf("official name of %s is %s\n", ptr, hptr->h_name);
	/* alle Aliasnamen ausgeben */
	while( (ptr = *(hptr->h_aliases)) != NULL ) {
		printf(" alias: %s\n", ptr);
		hptr->h_aliases++;
	}
}



