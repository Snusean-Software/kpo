#ifndef UNIX_SOCK_SESSION_H
#define UNIX_SOCK_SESSION_H

#include "session.h"

#include <iostream>

namespace net
{

class unix_sock_session : public session
{
public:
     unix_sock_session() = default;

     /// @copydoc
     void run() final;

     /// @copydoc
     std::string read() final;

     /// @copydoc
     void write( std::string message ) final;

     /// @copydoc
     void stop() final;

};

} // namespace network

#endif // UNIX_SOCK_SESSION_H