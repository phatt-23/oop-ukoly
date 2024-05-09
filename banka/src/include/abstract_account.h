#ifndef __ABSTRACT_ACCOUNT_H
#define __ABSTRACT_ACCOUNT_H

#include "precompiled.h"

class AbstractAccount {
    public:
        AbstractAccount();
        virtual ~AbstractAccount();
        virtual bool can_withdraw(double a) = 0;
};

#endif//__ABSTRACT_ACCOUNT_H
