#pragma once

#include <string>
#include <iostream>

namespace hasi::hasi_error
{
    void report(const std::string& context, const std::string& message, uint32_t line)
    {
        std::cout << context << " Error " << "[line" << line << "]: "<< message << std::endl;
    }
}