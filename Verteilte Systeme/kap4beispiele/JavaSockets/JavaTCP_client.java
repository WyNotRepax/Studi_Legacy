/** JavaTCP_client.java
 * Client Implementierung des Echo-Clients
 * nach dem Echo-Client im Sun-Java-Tutorial Custom Networking
 *
 * Bei java.lang.NoClassDefFoundError: JavaTCP_client 
 * muss auf der Konsole
 * unset CLASSPATH ausgefuehrt werden.
 * 
 * getestet unter Ubuntu 16.04 32Bit
 */

import java.io.*;
import java.net.*;

public class JavaTCP_client {
    public static void main(String[] args) throws IOException {

        Socket echoSocket = null;
        PrintWriter out = null;
        BufferedReader in = null;

        try {
            if (args.length != 2) {
           throw new IllegalArgumentException ("\nAufruf: JavaTCP_client <server> <port>\n\n");
        }
        echoSocket = new Socket(args[0], Integer.parseInt (args[1]));
            out = new PrintWriter(echoSocket.getOutputStream(), true);
            in = new BufferedReader(new InputStreamReader(
                                        echoSocket.getInputStream()));
        } catch (UnknownHostException e) {
            System.err.println("Ich kenne" + args[0] + "nicht.\n");
            System.exit(1);
        } catch (IOException e) {
            System.err.println("IOException beim Verbinden mit " + 
                  args[0] + "\nLaeuft der Echo-Server" +  
                  "(tcp_server)?\n");
            System.exit(1);
        }

        BufferedReader stdIn = new BufferedReader(
                                   new InputStreamReader(System.in));
        String userInput;

        while ((userInput = stdIn.readLine()) != null) {
            out.println(userInput);
            System.out.println(in.readLine());
            // echo-Kommentar entfernt, da dieser vom C-Server kommt.
        }

        out.close();
        in.close();
        stdIn.close();
        echoSocket.close();
    }
}

