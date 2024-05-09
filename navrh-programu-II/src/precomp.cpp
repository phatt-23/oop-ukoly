#include "inc/Precomp.h"

std::string tabs(int amount) 
{
    std::stringstream ss;
    for(int i = 0; i < amount; ++i) ss << "    ";
    return ss.str();
}