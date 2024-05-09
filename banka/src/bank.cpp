#include "include/bank.h"
#include "include/accountpartner.h"


#define ERROR "<<ERROR>> "
#define NOTE "<<NOTE>> "
#define FUNC "@fn: '" << __PRETTY_FUNCTION__ << "' "

#define __interest_rate_default__ 0.023
double Bank::s_default_ir = __interest_rate_default__;

void Bank::modify_default_if(double t_new_ir) {
    Bank::s_default_ir = t_new_ir;
    std::cout << Account::get_obj_count() << std::endl;
    for(uint32_t i = 0; i < Account::get_obj_count(); ++i) {
        if(m_accounts[i]->get_ir() != __interest_rate_default__)
            m_accounts[i]->set_ir(t_new_ir);
    }
}

Bank::Bank(int t_c, int t_a)
    : m_clients_count(t_c), m_clients_index(0)
    , m_accounts_count(t_a), m_accounts_index(0)
{
    this->m_clients = new Client*[t_c];
    this->m_accounts = new Account*[t_a];
}

Client* Bank::get_client(int t_c) {
    for(int i = 0; i < m_clients_index; ++i) {
        if(m_clients[i]->get_code() == t_c) return m_clients[i];
    }
    if(DBG)std::cout << ERROR << FUNC
        << "The client with presonal code " 
        << t_c << " wasn't found in the system!"
        << std::endl;
    return nullptr;
}

Account* Bank::get_account(int t_a) {
    for(int i = 0; i < m_accounts_index; ++i) {
        if(m_accounts[i]->get_number() == t_a) return m_accounts[i];
    }
    if(DBG)std::cout << ERROR << FUNC
        << "Account with number " << t_a << " wasn't found!" 
        << std::endl;
    return nullptr;
}

Client* Bank::create_client(int t_c, const char* t_n) {
    Client* c = new Client{t_c, t_n};
    m_clients[m_clients_index] = c;
    m_clients_index++;
    return c;
}

bool Bank::m_check_if_exits(int t_n) {
    for(int i = 0; i < m_accounts_index; ++i) {
        if(t_n == m_accounts[i]->get_number()) return true;
        if(DBG)std::cout << ERROR << FUNC
            << "Account with number " << t_n << " already exits!" 
            << std::endl; 
    }
    return false;
}


Account* Bank::create_account(int t_n, Client* t_c) {
    if(t_c != nullptr && !m_check_if_exits(t_n)) {
        Account* a = new Account(t_n, t_c);
        m_accounts[m_accounts_index] = a;
        m_accounts_index++;
        if(DBG) std::cout << NOTE << FUNC
            << "Account for the client (" 
            << t_c->get_code() << ", " << t_c->get_name() << ")" 
            << " was created!" << std::endl;

        return a;
    }

        if(DBG) std::cout << ERROR << FUNC 
            << "Account wasn't created!"
            << std::endl;
    return nullptr;
}

Account* Bank::create_account(int t_n, Client* t_c, double t_ir) {
    if(t_c != nullptr && !m_check_if_exits(t_n)) {
        Account* a = new Account{t_n, t_c, t_ir};
        m_accounts[m_accounts_index] = a;
        m_accounts_index++;
        if(DBG)
            std::cout 
            << "Accout for client ("
            << t_c->get_code() << ", " << t_c->get_name() << ")"
            << " was created!" << std::endl;

        return a;
    }
    if(DBG)
        std::cout << ERROR << FUNC
        << "Account wasn't created!"
        << std::endl;
    return nullptr;
}

#if 0
Account* Bank::create_account(int t_n, Client* t_c, Client* t_p) {
    if(t_c != nullptr && t_p != nullptr && !m_check_if_exits(t_n)) {
        Account* a = new Account{t_n, t_c, t_p};
        m_accounts[m_accounts_index] = a;
        m_accounts_index++;
        if(DBG)
            std::cout << NOTE << FUNC
            << "Accout for client ("
            << t_c->get_code() << ", " << t_c->get_name() << ")"
            << " alongside with partner ("
            << t_p->get_code() << ", " << t_c->get_name() << ")"
            << " was created!" << std::endl;
        return a;
    }
    if(DBG)
        std::cout << ERROR << FUNC 
        << "Account wasn't created!"
        << std::endl;
    return nullptr;
}

Account* Bank::create_account(int t_n, Client* t_c, Client* t_p, double t_ir) {
    if(t_c != nullptr && t_p != nullptr && !m_check_if_exits(t_n)) {
        Account* a = new Account{t_n, t_c, t_p, t_ir};
        m_accounts[m_accounts_index] = a;
        m_accounts_index++;
        return a;
    }
    if(DBG)
        std::cout << ERROR  << FUNC
        << "Account wasn't created!"
        << std::endl;
    return nullptr;
}
#endif

void Bank::add_interest() {
    for(int i = 0; i < m_accounts_index; ++i) {
        m_accounts[i]->add_interest();
    } 
    if(DBG)
        std::cout << NOTE << FUNC 
        << "Added interest to all accounts!" << std::endl;
}

#define INDENT "   "

void Bank::print() {
    printf("--------------- PRINT_OUT_BANK ---------------\n");
    printf("account count: %d, client count: %d, default IR: %.4lf\n", Account::get_obj_count(), Client::get_obj_count(), Bank::s_default_ir);
    printf("[Accounts] = {\n");
    for(int i = 0; i < m_accounts_index; ++i) {
        Account* tmp_a = m_accounts[i];
#if 0
        std::cout << INDENT
            << "{ "
            << "num = " << tmp_a->get_number() << ", "
            << "cash = " << tmp_a->get_balance() << ", "
            << "ir = " << tmp_a->get_ir() << ", "
            << "ow = (" << tmp_a->get_owner()->get_code() << ", " << tmp_a->get_owner()->get_name() << "), "
            << "pt = ("; 
        if(tmp_a->get_partner() == nullptr) {
            std::cout << "no-partner"; 
        } else {
            std::cout << tmp_a->get_partner()->get_code() << ", " << tmp_a->get_partner()->get_name();
        }
        std::cout 
            << ")"
            << " },"
            << std::endl;
#else
        tmp_a->print();
#endif
    }
    printf("};\n\n");

    printf("[Clients] = {\n");
    for(int i = 0; i < m_clients_index; ++i) {
        std::cout << INDENT 
            << "{ code = " <<m_clients[i]->get_code() << ", name = " << m_clients[i]->get_name() << " },"
            << std::endl;
    }
    printf("};\n");
    printf("-----------------------------------------------\n");
}

bool Bank::deposit_for(Account* t_a, double t_d) {
    for(int i = 0; i < m_accounts_index; ++i) {
        if(m_accounts[i] == t_a) {
            // printf("%p -> %p\n", t_a, m_accounts[i]);
            // printf("Found the user for deposit!\n");
            if(DBG)
                std::cout << NOTE << FUNC
                << "Deposited " << t_d << " for account " << t_a->get_number() 
                << std::endl;
            m_accounts[i]->deposit(t_d);
            return true;
        }
    }

    std::cout << ERROR << FUNC
        << "Couldn't find the account for deposit!" 
        << std::endl;
    return false;
}

bool Bank::withdraw_for(Account* t_a, double t_d) {
        for(int i = 0; i < m_accounts_index; ++i) {
        if(m_accounts[i] == t_a) {
            // printf("%p -> %p\n", t_a, m_accounts[i]);
            // printf("Found the user for withdraw!\n");
            if(m_accounts[i]->withdraw(t_d)) {
                if(DBG)
                    std::cout << NOTE << FUNC 
                    << "Withdrawn " << t_d << " for account " << t_a->get_number() << "." 
                    << std::endl; 
            }
            return true;
        }
    }

    std::cout << ERROR  << FUNC
        << "Couldn't find the account for withdraw!" 
        << std::endl;
    return false;
}

PartnerAccount* Bank::create_account(int t_n, Client* t_c, Client* t_p) 
{
    if(t_c != nullptr && t_p != nullptr && !m_check_if_exits(t_n)) {
        PartnerAccount* a = new PartnerAccount{t_n, t_c, t_p};
        m_accounts[m_accounts_index] = a;
        m_accounts_index++;
        if(DBG)
            std::cout << NOTE << FUNC
            << "Accout for client ("
            << t_c->get_code() << ", " << t_c->get_name() << ")"
            << " alongside with partner ("
            << t_p->get_code() << ", " << t_c->get_name() << ")"
            << " was created!" << std::endl;
        return a;
    }
    if(DBG)
        std::cout << ERROR << FUNC 
        << "Account wasn't created!"
        << std::endl;
    return nullptr;
}
PartnerAccount* Bank::create_account(int t_n, Client* t_c, Client* t_p, double t_ir) {
    if(t_c != nullptr && t_p != nullptr && !m_check_if_exits(t_n)) {
        PartnerAccount* a = new PartnerAccount{t_n, t_c, t_p, t_ir};
        m_accounts[m_accounts_index] = a;
        m_accounts_index++;
        return a;
    }
    if(DBG)
        std::cout << ERROR  << FUNC
        << "Account wasn't created!"
        << std::endl;
    return nullptr;
}


Bank::~Bank() {
    if(DBG)printf("INFO: %s\n", __PRETTY_FUNCTION__);
    for(int i = 0; i < m_accounts_index; ++i) {
        delete m_accounts[i];
    }
    for(int i = 0; i < m_clients_index; ++i) {
        delete m_clients[i];
    }
}

CreditAccount* Bank::create_credit_account(int t_n, Client* t_c, double credit) {
    if(t_c != nullptr) {
        CreditAccount* a = new CreditAccount{t_n, t_c, credit};
        m_accounts[m_accounts_index] = a;
        m_accounts_index++;
        return a;
    }
    if(DBG)
        std::cout << ERROR  << FUNC
        << "Account wasn't created!"
        << std::endl;
    return nullptr;
}
