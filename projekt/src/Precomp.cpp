#include "inc/Precomp.h"

// empty

std::string tabs(int tabSize)
{
    std::string tabString;
    for(int i = 0; i < tabSize; ++i) tabString += "    ";
    return tabString;
}

int __DESCRIPTION_LENGTH = 60;