#ifndef __ACCOUNT_H
#define __ACCOUNT_H

#include "abstract_account.h"
#include "client.h"

#define DEFAULT_IR 0.023

class Account : public AbstractAccount {
private:
    static uint32_t s_account_count;
    int     m_number = 0;
    double  m_interest_rate = DEFAULT_IR;

    Client* m_owner   = nullptr;
    Client* m_partner = nullptr;
    double  m_balance = 0;

protected:

public:
    static uint32_t get_obj_count();

    Account(int t_n, Client* t_c);
    Account(int t_n, Client* t_c, double t_ir);
    Account(int t_n, Client* t_c, Client* t_p);
    Account(int t_n, Client* t_c, Client* t_p, double t_ir);
    virtual ~Account();
    int     get_number();
    double  get_balance();
    double  get_ir();
    void    set_ir(double t_ir);
    Client* get_owner();
    Client* get_partner();
    void    set_balance(double a);
    virtual bool can_withdraw(double t_a);
    void    deposit(double t_a);
    virtual bool withdraw(double t_a);
    void    add_interest();
    virtual void print();
};


#endif//__ACCOUNT_H
