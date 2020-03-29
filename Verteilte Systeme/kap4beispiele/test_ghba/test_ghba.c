/*
 * Beispiel test_ghba.c: Benutzung der Systemfunktion gethostbyaddr()
 * getestet unter Ubuntu 10.04 32Bit
 */

#include <stdio.h>
#include <sys/types.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int  main(int argc, char *argv[]) {

    char *ptr;
    struct hostent *hptr;        /* fuer gethostbyaddr */
    struct in_addr *aptr, addr;    /* fuer IP Adressen */

    /* Schleife uber alle Argumente */
    while(--argc > 0 ) {
        /* naechstes Argument */
        ptr = *++argv;
        /* umwandeln */
        addr.s_addr = inet_addr(ptr);
        /* gethostyaddr aufrufen */
        if( (hptr = gethostbyaddr( (char *)&addr,
                    sizeof(struct in_addr),
                    AF_INET )) == NULL ) {
            fprintf(stderr, "gethostbyaddr fails for %s\n", ptr);
            /* naechstes Argument */
            continue;
        }
        printf("official name of %s is %s\n", ptr, hptr->h_name);

        /* alle Aliasnamen ausgeben */
        while( (ptr = *(hptr->h_aliases)) != NULL ) {
            printf("    alias: %s\n", ptr);
            hptr->h_aliases++;
        }

        /* Adresstyp usw. ausgeben */
        printf("    addr. type = %d, addr. length = %d\n",
            hptr->h_addrtype, hptr->h_length);

        switch( hptr->h_addrtype ) {
        case AF_INET:
            /* Adressen ausgeben */
            while( (aptr = (struct in_addr *)*(hptr->h_addr_list))
                != NULL ) {
                printf("    IP address: %s\n",
                    inet_ntoa(*aptr));
                hptr->h_addr_list++;
            }
            break;
        default:
            printf("Unknown address type\n");
            break;
        }  /* of while ptr */
    }   /* of while -ptr */
}  /* of main */

