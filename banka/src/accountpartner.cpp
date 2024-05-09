#include "include/accountpartner.h"

PartnerAccount::PartnerAccount(int n, Client* o, Client* p) 
: Account(n, o), m_partner(p)
{
    if(DBG)printf("INFO: %s\n", __PRETTY_FUNCTION__);
}

PartnerAccount::PartnerAccount(int n, Client* o, Client* p, double ir) 
: Account(n, o, ir), m_partner(p)
{
    if(DBG)printf("INFO: %s\n", __PRETTY_FUNCTION__);
}

Client* PartnerAccount::get_partner() {
    return m_partner;
}

PartnerAccount::~PartnerAccount() {
    if(DBG)printf("INFO: %s\n", __PRETTY_FUNCTION__);
}

void PartnerAccount::print() {
    printf("\tClass PartnerAccount => #: %d, ir: %f, $: %f ||| ", get_number(), get_ir(), get_balance());
    printf("partner: code: %d, name: %s\n", 
            get_partner()->get_code(), get_partner()->get_name().c_str());
}
