#ifndef UNIX_SOCK_SESSION_H
#define UNIX_SOCK_SESSION_H

#include "session.h"

#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

namespace net
{

class unix_sock_session : public session
{
public:
     unix_sock_session( const std::string& server_addr );

     ~unix_sock_session();

     /// @copydoc
     void run() final;

     /// @copydoc
     std::string read() final;

     /// @copydoc
     void write( const std::string& message ) final;

     /// @copydoc
     void stop() final;

private:
     int client_sock_;
     sockaddr_un server_addr_;
     bool running_;
     char* read_buffer_;
     const size_t buffer_size_;
};

} // namespace net

#endif // UNIX_SOCK_SESSION_H