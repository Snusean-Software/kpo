#include "impl/unix_sock_session.h"

#include <cassert>
#include <thread>
#include <chrono>
#include <stdexcept>

namespace net
{

unix_sock_session::unix_sock_session( const std::string& server_addr )
     : client_sock_ { -1 }
     , server_addr_ { 0 }
     , running_ { false }
     , buffer_size_ { 1024 }
     , read_buffer_ { nullptr }
{
     server_addr_.sun_family = AF_UNIX;
     assert( server_addr.length() < 100 && "server_addr is too big" );
     strcpy( server_addr_.sun_path, server_addr.c_str() );
     read_buffer_ = new char[ buffer_size_ ];
}

unix_sock_session::~unix_sock_session()
{
     if ( running_ )
     {
          stop();
     }
     delete[] read_buffer_;
     read_buffer_ = nullptr;
}

void unix_sock_session::run()
{
     constexpr int WAIT_FOR_RECONNECT = 100;
     while ( !running_ )
     {
          int ec = connect( client_sock_, reinterpret_cast<sockaddr*>( &server_addr_ ), sizeof( server_addr_ ) );
          running_ = ( ec == 0 );
          std::this_thread::sleep_for( std::chrono::milliseconds( WAIT_FOR_RECONNECT ) );
     }
}

std::string unix_sock_session::read()
{
     if ( !running_ )
     {
          throw std::runtime_error( "Session: try to read while session is not running" );
     }

     int ec = recv( client_sock_, read_buffer_, buffer_size_, 0 );
     if ( ec == EINTR )
     {
          // recv was interrupted, its fine
          return "";
     }
     if ( ec != 0 )
     {
          throw std::runtime_error( "Session: read error" );
     }

     return std::string { read_buffer_ };
}

void unix_sock_session::write( const std::string& message )
{
     if ( !running_ )
     {
          throw std::runtime_error( "Session: try to write while session is not running" );
     }

     int ec = send( client_sock_, message.c_str(), message.length() + 1, MSG_NOSIGNAL );
     if ( ec == EINTR )
     {
          return;
     }
     if ( ec != 0 )
     {
          throw std::runtime_error( "Session: write error" );
     }
}

void unix_sock_session::stop()
{
     shutdown( client_sock_, SHUT_RDWR );
     close( client_sock_ );
     running_ = false;
}

} // namespace net