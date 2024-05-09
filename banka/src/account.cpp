#include "include/account.h"

#define ERROR "<<ERROR>> "
#define FUNC  "@fn: '" << __PRETTY_FUNCTION__ << "' "

uint32_t Account::s_account_count = 0;

uint32_t Account::get_obj_count() {
    return Account::s_account_count;
}

Account::Account(int t_n, Client* t_c)
    : m_number(t_n), m_owner(t_c)
{
    if(DBG) printf("INFO: %s\n", __PRETTY_FUNCTION__);
    Account::s_account_count += 1;
}

Account::Account(int t_n, Client* t_c, double t_ir)
    : m_number(t_n)
    , m_interest_rate(t_ir)
    , m_owner(t_c)
{
    if(DBG)printf("INFO: %s\n", __PRETTY_FUNCTION__);
    Account::s_account_count += 1;
}

Account::Account(int t_n, Client* t_c, Client* t_p)
    : m_number(t_n)
    , m_owner(t_c)
    , m_partner(t_p)
{
    if(DBG)printf("INFO: %s\n", __PRETTY_FUNCTION__);
    Account::s_account_count += 1;
}

Account::Account(int t_n, Client* t_c, Client* t_p, double t_ir)
    : m_number(t_n)
    , m_interest_rate(t_ir)
    , m_owner(t_c)
    , m_partner(t_p)
{
    if(DBG)printf("INFO: %s\n", __PRETTY_FUNCTION__);
    Account::s_account_count += 1;
}

int Account::get_number() {
    return this->m_number;
}

double Account::get_balance() {
    return this->m_balance;    
}

double Account::get_ir() {
    return this->m_interest_rate;
}

void Account::set_ir(double t_ir) {
    m_interest_rate = t_ir;
}

Client* Account::get_owner() {
    return this->m_owner;
}

Client* Account::get_partner() {
    return m_partner;
}

bool Account::can_withdraw(double t_a) {
    double bal = m_balance;    
    if(bal - t_a >= 0) {
        return true;
    } else return false;
}

void Account::deposit(double t_a) {
    m_balance += t_a;
}

bool Account::withdraw(double t_a) {
    if(can_withdraw(t_a)) {
        m_balance -= t_a;
        return true;
    } else {
        if(0) std::cout << ERROR << FUNC
            << "Insifficient funds for withdraw!"
            << std::endl;
        return false;
    }
}

void Account::add_interest() {
    m_balance += m_balance * m_interest_rate;
}

Account::~Account() {
    // if(DBG)
        printf("INFO: %s\n", __PRETTY_FUNCTION__);
}

void Account::set_balance(double a) {
    if(m_balance >= a) m_balance -= a;
}

void Account::print() {
    printf("\tClass Account => #: %d, ir: %f, $: %f\n", m_number, m_interest_rate, m_balance);
}

