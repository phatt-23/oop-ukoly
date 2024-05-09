#ifndef __credit_account_h__
#define __credit_account_h__

#include "account.h"

class CreditAccount : public Account {
    double m_credit;

public:
    CreditAccount(int n, Client* o, double c);
    CreditAccount(int n, Client* o, double ir, double c);
    ~CreditAccount();

    bool can_withdraw(double t_a) override;
    bool withdraw(double t_a) override;
    void print() override;
};

#endif//__credit_account_h__
