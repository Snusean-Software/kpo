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

void console_io::put( std::string message )
{
     std::cout << message;
}

} // namespace io