#include "include/bank.h"

#define ARRLEN(x) sizeof(x)/sizeof(*x)
const int cli_id_base = 123456;
const int acc_id_base = 789456;

struct Person {
    const char* m_name;
    const int   m_id;
};

Person people_list[] = {
    { "Person_1", cli_id_base * 1 }, 
    { "Person_2", cli_id_base * 2 }, 
    { "Person_3", cli_id_base * 3 }, 
    { "Person_4", cli_id_base * 4 }, 
    { "Person_5", cli_id_base * 5 }, 
    { "Person_6", cli_id_base * 6 },
    { "Person_7", cli_id_base * 7 },
    { "Person_8", cli_id_base * 8 },
    { "Person_9", cli_id_base * 9 },
    { "Person_10", cli_id_base * 10 },
    { "Person_11", cli_id_base * 11 },
};

// main funkce i s bankou
#if 1
int main() {
    const int N = ARRLEN(people_list);
    Bank b1{1000, 1000};

    // vytvoření klientů v bance - Client
    for(Person p : people_list)
        b1.create_client(p.m_id, p.m_name);

    // vytvoření účtů některých klientů - Account
    for(int i = 1; i <= N/2 ; ++i)
        b1.create_account(acc_id_base*i, b1.get_client(cli_id_base*i));

    // vytvoření účtů s partnerem - PartnerAccount
    for(int i = N/2; i < 2 * N/2; ++i)
        b1.create_account(acc_id_base*i, b1.get_client(cli_id_base*i), b1.get_client(cli_id_base*(i+1)), 0.038);

    // vytvoření pár CreditAccount 
    for(int i = N/2; i < 2 * N/2; ++i)
        b1.create_credit_account(1, b1.get_client(cli_id_base*i), 1000);

    b1.print(); // výpis banky 

    return 0;
}
#endif

// main funkce z prezentace - použití čistě abstraktní třídy
#if 0
int main() {
    Client* o = new Client(0, "Smith");
    CreditAccount* ca = new CreditAccount(1, o, 1000);
    AbstractAccount* aa = ca;

    delete aa;
    delete o;

    return 0;
}
#endif



    // vkládání peněz do účtů
    // for(int i = 1; i <= 2 * N/2; ++i) {
        // b1.deposit_for(b1.get_account(acc_id_base*i), 5000.05*i);
    // }

    // po vložení peněz
    // b1.print();
    
    // výběr peněz z účtů
    // for(int i = 1; i <= 3; ++i) {
        // b1.withdraw_for(b1.get_account(acc_id_base*i), 4000.05*i);
    // }

    // po výběru peněz
    // b1.print();

    // adice úroků do účtů
    // b1.add_interest();
    
    // pridání úrokové sazby 
    // b1.print();

    // změna úrokové sazby (v bance i pro všechny její účty)
    // b1.modify_default_if(0.0589);
    // b1.print();
    
//     return 0;
// }

// int main() {
//     Client* o = new Client(0, "Smith");
//     CreditAccount* ca = new CreditAccount(1, o, 1000);

//     std::cout << "credit account: " << ca->can_withdraw(1000) << std::endl;

//     Account* a = ca;

//     std::cout << "basic account: " << a->can_withdraw(1000) << std::endl;
//     std::cout << "ca can withdraw: " << ca->withdraw(1000) << std::endl;

//     std::cout << "remaining balance: " << ca->get_balance() << std::endl;

//     a = nullptr;
//     // delete ca;

//     return 0;
// }

