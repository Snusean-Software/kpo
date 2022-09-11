#include "impl/console_io.h"

#include <iostream>

namespace io
{

std::string console_io::get()
{
     std::string result;
     std::cin >> result;
     return result;
}

void console_io::put( const std::string& message )
{
     std::cout << message << std::endl;
}

} // namespace io