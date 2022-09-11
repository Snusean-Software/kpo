#ifndef CONSOLE_IO_H
#define CONSOLE_IO_H

#include "io_iface.h"

#include <string>

namespace io
{

class console_io : public io_iface
{
public:
     console_io() = default;

     /// @copydoc
     std::string get() final;

     /// @copydoc
     void put( const std::string& message ) final;
};

} // namespace io

#endif // CONSOLE_IO_H