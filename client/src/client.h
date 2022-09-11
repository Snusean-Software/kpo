#ifndef CLIENT_H
#define CLIENT_H

#include "user_io/io_iface.h"
#include "network/session.h"

#include <string>
#include <memory>
#include <thread>

using client_id = std::string;

class client
{
public:
     /// @brief client constructor
     /// @param id client identifier
     /// @param session network context
     /// @param io user input/output interface
     client( const client_id& id, std::unique_ptr<net::session> session, std::shared_ptr<io::io_iface> io );

     // copy is forbidden
     client( const client& ) = delete;
     client& operator=( const client& other ) = delete;

     ~client();

     /// @brief send message through network context 
     /// @param message message to be sended
     void send_message( const std::string& message ); 

private:
     /// @brief Adds client id to message
     /// @param message unprepared message
     /// @return prepared message
     std::string prepare_message( const std::string& message ) const;

private:
     client_id id_;
     std::unique_ptr<net::session> session_;
     std::shared_ptr<io::io_iface> io_;

     std::thread reader_;
     std::thread writer_;

};

#endif // CLIENT_H