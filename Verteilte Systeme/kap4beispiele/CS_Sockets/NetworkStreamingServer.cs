/* Aus dem Buch Programmieren mit C# von Jesse Liberty, 2. Aufl. O'Reilly  2005
 * ungetestet uebernommen
 */


#region Using directives

using System;
using System.Collections.Generic;
using System.Net;
using System.Net.Sockets;
using System.Text;

#endregion

namespace NetworkStreamingServer
{
   public class NetworkIOServer
   {

      public static void Main()
      {
         NetworkIOServer app =
            new NetworkIOServer();
         app.Run();
      }

      private void Run()
      {
         // create a new TcpListener and start it up
         // listening on port 65000

         IPAddress localAddr = IPAddress.Parse( "127.0.0.1" );
         TcpListener tcpListener = new TcpListener( localAddr, 65000 );
         tcpListener.Start();

         // keep listening until you send the file
         for ( ; ; )
         {
            // if a client connects, accept the connection
            // and return a new socket named socketForClient
            // while tcpListener keeps listening
            Socket socketForClient =
               tcpListener.AcceptSocket();
               Console.WriteLine( "Client connected" );

               // call the helper method to send the file
               SendFileToClient( socketForClient );

               Console.WriteLine(
                  "Disconnecting from client..." );

               // clean up and go home
               socketForClient.Close();
               Console.WriteLine( "Exiting..." );
               break;

         }
      }

      // helper method to send the file
      private void SendFileToClient(
         Socket socketForClient )
      {
         // create a network stream and a stream writer 
         // on that network stream
         NetworkStream networkStream =
            new NetworkStream( socketForClient );
         System.IO.StreamWriter streamWriter =
            new System.IO.StreamWriter( networkStream );

         // create a stream reader for the file
         System.IO.StreamReader streamReader =
            new System.IO.StreamReader(
               @"C:\test\source\myTest.txt" );

         string theString;

         // iterate through the file, sending it 
         // line-by-line to the client
         do
         {
            theString = streamReader.ReadLine();

            if ( theString != null )
            {
               Console.WriteLine(
                  "Sending {0}", theString );
               streamWriter.WriteLine( theString );
               streamWriter.Flush();
            }
         }
         while ( theString != null );

         // tidy up
         streamReader.Close();
         networkStream.Close();
         streamWriter.Close();
      }
   }
}
