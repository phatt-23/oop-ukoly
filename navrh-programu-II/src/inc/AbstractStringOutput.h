#ifndef ABSTRACT_STRING_OUTPUT_H
#define ABSTRACT_STRING_OUTPUT_H

#include "Precomp.h"

class AbstractStringOutput
{
    private:

    public:
        AbstractStringOutput();
        virtual ~AbstractStringOutput();
        virtual std::string toString(int tab_amount) const = 0;
};

#endif//ABSTRACT_STRING_OUTPUT_H