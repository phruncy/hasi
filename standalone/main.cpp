#include <hasi.h>
#include <iostream>
#include <fstream>
#include <sstream>

void report(const char* message);

int main(int argc, char* argv[])
{   
    if (argc == 1)
    {
        report("Must specify input file name!");
        return 1;
    }
    std::ifstream ifs;
    ifs.open(argv[1], std::ifstream::in);
    if (!ifs.good())
    {
        report("Bad input file.");
        return 2;
    }

    std::stringstream input;
    input << ifs.rdbuf();
    ifs.close();
    std::string source = input.str();
    hasi::Scanner scanner(source);
    scanner.scan();
    ifs.close();
    if (scanner.hadError())
        return 3;
    hasi::debug::printTokens(scanner.getTokens());
    return 0;
}

void report(const char* message)
{
    std::cout << "[Hasi] " << message << std::endl;
}