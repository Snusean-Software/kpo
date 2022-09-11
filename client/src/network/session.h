#ifndef SESSION_H
#define SESSION_H

#include <string>

namespace net
{

class session
{
public:
     /// @brief start session, after this it is able to read and write
     virtual void run() = 0;

     /// @brief read all data from session
     /// @return readed data
     virtual std::string read() = 0;

     /// @brief write data to session
     /// @param message data to be written  
     virtual void write( std::string message ) = 0;

     /// @brief stop session
     virtual void stop() = 0;

     virtual ~session() = default;
};

} // namespcae network

#endif // SESSION_H