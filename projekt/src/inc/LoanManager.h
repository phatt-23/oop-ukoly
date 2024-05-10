#ifndef __LIBRARY_LOAN_MANAGING_MODULE_H
#define __LIBRARY_LOAN_MANAGING_MODULE_H

#include "StringOutput.h"
#include "Loan.h"

class LoanManager : public StringOutput
{
    private:
        std::map<int, std::shared_ptr<Loan>> loan_list;

    public:
        LoanManager();
        ~LoanManager() override;

        std::shared_ptr<Loan> addLoan(int keyID, std::shared_ptr<Member> member, std::shared_ptr<Librarian> librarian, time_t timeOfLoan);

        std::shared_ptr<Loan> getLoan(int keyID);

        bool isLoanKeyIdFree(int loanKeyID);

        std::string toStr(int tabSize) override;
};

#endif//__LIBRARY_LOAN_MANAGING_MODULE_H