#include "client.h"
#include "network/impl/unix_sock_session.h"
#include "user_io/impl/console_io.h"

#include <iostream>

int main()
{
     try
     {
          auto user_io = std::shared_ptr<io::io_iface>( new io::console_io() );

          client c( client_id( "test-id" ),
                    std::unique_ptr<net::session>( new net::unix_sock_session() ),
                    user_io );

          c.send_message("Test\n");

          return 0;
     }
     catch ( const std::exception& e )
     {
          std::cout << e.what();
          return -1;
     }
}