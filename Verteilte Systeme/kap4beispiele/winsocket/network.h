///////////////////////////////////////////////////////////////////////////////////////////////// 
//
// newtork - Bibliothek   - mit Beiträgen aus MSDN (MicrosoftDevleoper Network) und Stevens, 
// Unix Network Programming bzw. dem Skript Verteilte Systeme des vierten Semesters
//
// C. Westerkamp HS Osnabrueck, SS2011
//
// Version 1.0: sendcmd-Funktion, die ein UDP-Datagramm an Localhost sendet.
//
///////////////////////////////////////////////////////////////////////////////////////////////

// verhindert doppeltes Inkludieren: 
#ifndef NETWORK_H
#define NETWORK_H

#include <winsock2.h>
#include <Ws2tcpip.h>
#include <windows.h>
#include <winsock.h>
#include <time.h>
#define VISUALISIERUNGS_IP "127.0.0.1" //Visualisierung laeuft auf gleichem Rechner (localhost)

int send_cmd(char *);  

#endif // #ifndef NETWORK_H

