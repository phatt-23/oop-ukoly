#include "include/credit_account.h"

CreditAccount::CreditAccount(int n, Client* o, double c) 
: Account(n, o)
, m_credit(c)
{
    
}

CreditAccount::CreditAccount(int n, Client* o, double ir, double c)
: Account(n, o, ir)
, m_credit(c)
{
    
}

CreditAccount::~CreditAccount() {
    // if(DBG)
        printf("INFO: %s\n", __PRETTY_FUNCTION__);
}
bool CreditAccount::can_withdraw(double t_a)
{
    return ((m_credit + this->get_balance()) >= t_a) ? true : false;
}

bool CreditAccount::withdraw(double t_a) {
    if(can_withdraw(t_a)) { // first try balance
        set_balance(get_balance() - t_a);
        return true;
    }
    return false; 
}

void CreditAccount::print() {
    printf("\tClass CreditAccount => #: %d, ir: %f, $: %f, credit: %f\n", get_number(), get_ir(), get_balance(), m_credit);
    
}
