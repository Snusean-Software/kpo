#ifndef IO_IFACE_H
#define IO_IFACE_H

#include <string>

namespace io
{

class io_iface
{
public:
     /// @brief get data
     /// @return received data
     virtual std::string get() = 0;

     /// @brief put data
     /// @param message data to be putted
     virtual void put( std::string message ) = 0;

     virtual ~io_iface() = default;
};

} // namespace io

#endif // IO_IFACE_H