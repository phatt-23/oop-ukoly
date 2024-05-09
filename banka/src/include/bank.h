#ifndef __BANK_H
#define __BANK_H

#include "accountpartner.h"
#include "credit_account.h"

class Bank {
private:
    static double s_default_ir;

    Client** m_clients;
    int m_clients_count;
    int m_clients_index;
    Account** m_accounts;
    int m_accounts_count;
    int m_accounts_index;

public:

    Bank(int t_c, int t_a);
    ~Bank();
    Client*  get_client(int t_c);
    Account* get_account(int t_a);
    Client*  create_client(int t_c, const char* t_n);
    Account* create_account(int t_n, Client* t_c);
    Account* create_account(int t_n, Client* t_c, double t_ir);
    // Account* create_account(int t_n, Client* t_c, Client* t_p);
    // Account* create_account(int t_n, Client* t_c, Client* t_p, double t_ir);
    CreditAccount* create_credit_account(int t_n, Client* t_c, double credit);
    //     b1.create_credit_account(1, b1.get_client(cli_id_base*2), 1000);

    PartnerAccount* create_account(int t_n, Client* o, Client* p);
    PartnerAccount* create_account(int t_n, Client* o, Client* p, double ir);
    void     add_interest();
    void     print();
    bool     m_check_if_exits(int t_n);
    bool     deposit_for(Account* t_a, double t_d);
    bool     withdraw_for(Account* t_a, double t_d);
    void     modify_default_if(double t_new_ir);
};

#endif//__BANK_H
