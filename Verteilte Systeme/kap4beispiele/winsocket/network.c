#include <stdio.h>
#include "network.h"
// Link with ws2_32.lib
#pragma comment(lib, "Ws2_32.lib")

// Diese Funktion nicht veraendern!!
int send_cmd(char *cmd){
	// Mit Abschnitten aus http://msdn.microsoft.com/en-us/library/ms740148(VS.85).aspx
	// Funktionen mit WS... sind Windows-spezifisch, weitere Infos im 
	// Fach Verteilte Systeme im vierten Semester
	// Die Übertragung erfolgt ungesichert per UDP
    WSADATA wsaData;
    SOCKET SendSocket = INVALID_SOCKET;
    struct sockaddr_in RecvAddr;

    unsigned short Port = 45454;  // Port der Visualisierung 

    char SendBuf[1024];
    int BufLen = 1024;
    int iResult;
	//----------------------
    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR) {
        printf("Error in send_cmd(): WSAStartup failed with error: %d\n", iResult);
        return 1;
    }
    //---------------------------------------------
    // Create a socket for sending data
    SendSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (SendSocket == INVALID_SOCKET) {
        printf("Error in send_cmd(): socket failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    //---------------------------------------------
    // Set up the RecvAddr structure with the IP address of
    // the receiver (in this example case localhost)
    // and the specified port number.
    RecvAddr.sin_family = AF_INET;
    RecvAddr.sin_port = htons(Port);
    RecvAddr.sin_addr.s_addr = inet_addr(VISUALISIERUNGS_IP);

    //---------------------------------------------
    // Send a datagram to the receiver
	
	// Einziger bisher implementeirter Befehl: toggle zum Umschalten der Ampeln
	// Gelbphase wird von Visualisierung automatisch zwischen geschaltet
	strcpy(SendBuf, cmd);
	iResult = sendto(SendSocket,
                     SendBuf, BufLen, 0, (SOCKADDR *) & RecvAddr, sizeof (RecvAddr));
    if (iResult == SOCKET_ERROR) {
        printf("Error in send_cmd(): sendto failed with error: %d\n", WSAGetLastError());
        closesocket(SendSocket);
        WSACleanup();
        return 1;
    }
 	
	//---------------------------------------------
    // When the application is finished sending, close the socket.
    iResult = closesocket(SendSocket); //Win-spezfisch, Unix: close(..)
    if (iResult == SOCKET_ERROR) {
        printf("Error in send_cmd(): closesocket failed with error: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    //---------------------------------------------
    // Clean up and quit.
    WSACleanup();
	return 0;
}
