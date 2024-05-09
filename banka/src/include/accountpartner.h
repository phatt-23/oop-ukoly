#ifndef __account_partner_h__
#define __account_partner_h__

#include "account.h"

class PartnerAccount : public Account {
private:
    Client* m_partner;

public:    
    PartnerAccount(int n, Client* o, Client* p);
    PartnerAccount(int n, Client* o, Client* p, double ir);
    ~PartnerAccount();
    Client* get_partner();
    void print() override;
};

#endif//__account_partner_h__
