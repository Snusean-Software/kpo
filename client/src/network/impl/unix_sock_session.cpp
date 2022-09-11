#include "impl/unix_sock_session.h"

#include <cassert>
#include <thread>
#include <chrono>
#include <iostream>

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
     close( client_sock_ );
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
     if ( ec != 0 )
     {
          throw std::runtime_error( "Session: read error" );
     }

     return std::string { read_buffer_ };
}

void unix_sock_session::write( std::string message )
{
     std::cerr << "Not implemented" << std::endl;
}

void unix_sock_session::stop()
{
     shutdown( client_sock_, SHUT_RDWR );
}

} // namespace net