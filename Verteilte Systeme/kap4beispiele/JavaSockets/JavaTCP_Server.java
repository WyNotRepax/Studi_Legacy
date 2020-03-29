package javatcp_server;

import java.io.*; import java.net.*;

public class JavaTCP_Server {
  final static short port = 8998; 
  final static int backlog = 10; 
	/* Implementiert Echo-Service */
        private static void handleConnection (Socket wSocket) {
        System.out.println("Verbunden mit " + wSocket);
        try {
            PrintStream ps = new PrintStream(wSocket.getOutputStream());
            BufferedReader in = new BufferedReader(new InputStreamReader(
                    wSocket.getInputStream()));
            String clientMsg;
            while ((clientMsg = in.readLine()) != null) {
                System.out.println("> " + clientMsg);
                ps.println("Echo: " + clientMsg);
            }
            wSocket.close();
        } catch (IOException e) {
            System.err.println("Verbindung abgebrochen.");
            /* der naechste Client kann nun bedient werden */
        }
    }

    public static void main (String[] args) {
        ServerSocket lSocket = null;
        try {
            lSocket = new ServerSocket (port, backlog);
        } catch (IOException e) {
            System.err.println("Server Socket auf " + port + 
                    " kann nicht erzeugt werden.");
            System.exit(1);
        }
        while (true) {
            System.out.println("Warte auf Verbindung... ");
            Socket wSocket;
            try {
                wSocket = lSocket.accept();
            } catch (IOException e) {
                System.err.println("Eingehende  Verbindung nicht moeglich.");
                continue;
            }
            handleConnection(wSocket);
        }
    }
}
  