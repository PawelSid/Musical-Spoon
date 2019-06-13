#include "interface.h"

int Interface::extract_int_from_string(std::string str){
    int out;
    std::istringstream ( str ) >> out;
    return out;
}

void Interface::print(std::string s){

}
