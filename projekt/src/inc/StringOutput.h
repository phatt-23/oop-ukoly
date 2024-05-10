#ifndef __STRING_OUTPUT_H
#define __STRING_OUTPUT_H

#include "Precomp.h"

class StringOutput
{
    public:
        StringOutput();
        virtual ~StringOutput();
        virtual std::string toStr(int tabSize) = 0;
};

#endif//__STRING_OUTPUT_H