/** Aus dem Buch Programmieren mit C# von Jesse Liberty, 2. Aufl. O'Reilly  2005
 *  ungetestet uebernommen
 */

#region Using directives

using System;
using System.Collections.Generic;
using System.Net.Sockets;
using System.Text;

#endregion

namespace NetworkStreamingClient
{
   public class Client
   {

      static public void Main( string[] Args )
      {

         // create a TcpClient to talk to the server
         TcpClient socketForServer;

         try
         {
            socketForServer =
               new TcpClient( "localHost", 65000 );
         }
         catch
         {
            Console.WriteLine(
               "Failed to connect to server at {0}:65000",
                  "localhost" );
            return;
         }

         // create the Network Stream and the Stream Reader object
         NetworkStream networkStream =
               socketForServer.GetStream();
         System.IO.StreamReader streamReader =
            new System.IO.StreamReader( networkStream );

         try
         {
            string outputString;

            // read the data from the host and display it
            do
            {
               outputString = streamReader.ReadLine();

               if ( outputString != null )
               {
                  Console.WriteLine( outputString );
               }
            }
            while ( outputString != null );
         }
         catch
         {
            Console.WriteLine(
               "Exception reading from Server" );
         }

         // tidy up 
         networkStream.Close();
      }
   }
}
