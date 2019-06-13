#include <iostream>
#include <string>
#include <sstream>
class Interface
{
    public:
        int extract_int_from_string(std::string s);
        double extract_double_from_string(std::string s);
        void print(std::string s);
};
