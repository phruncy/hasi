#pragma once

#include <string>
#include <iostream>

namespace hasi::hasi_error
{
    void report(const std::string& context, const std::string& message)
    {
        std::cout << context << " Error: " << message << std::endl;
    }
}