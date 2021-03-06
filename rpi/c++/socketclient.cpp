#include "socketclient.h"
#include "Log.h"
#include <errno.h>

#define TIMEOUT 5

socketclient::socketclient(const Config& cfg)
{
  sock = -1;
  port = 0;
  address = "";

  Log::get().debug("socketclient constructed");
}
 
/**
   Connect to a host on a certain port number
*/
bool socketclient::conn(string address , int port)
{
  // create socket if it is not already created
  if(sock == -1)
  {
    //Create socket
    errno = 0;
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
      string msg = "Could not create socket. errno = ";
      msg += strerror(errno);
      Log::get().error(msg);
      disconn();
      return false;
    }
  }

  // Set server paramters
  server.sin_addr.s_addr = inet_addr( address.c_str() );
  if( server.sin_addr.s_addr == (in_addr_t)(-1) )
  {
    Log::get().error("Socket connection failed. Bad IP address");
    disconn();
    return false;
  }
  server.sin_family = AF_INET;
  server.sin_port = htons( port );
     
  // Connect to remote server & send package
  errno = 0;
  if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
  {
    string msg = "Socket connection failed. ";
    msg += ", errno = ";
    msg += strerror(errno);
    Log::get().error(msg);
    disconn();
    return false;
  }
     
  return true;
}
 
/**
   Send data to the connected host
*/
bool socketclient::submit(string data)
{
  //Send some data
  errno = 0;
  if( send(sock, data.c_str(), strlen( data.c_str() ), TIMEOUT) < 0)
  {
    string msg = "Socket send_data failed. Data: ";
    msg += data;
    msg += ". errno = ";
    msg += strerror(errno);
    Log::get().error(msg);
    disconn();
    return false;
  }
  return true;
}
 
/**
   Receive data from the connected host
*/
void socketclient::disconn(void)
{
  if(sock == -1)
    return;
  close(sock);
  sock = -1;
  
  /*
  if( shutdown(sock,SHUT_RDWR) )
    Log::get().error("Unable to shutdown socket");
  sock = -1;
  */
}
