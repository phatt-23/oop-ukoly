#include "inc/LoanManager.h"

LoanManager::LoanManager() = default;

LoanManager::~LoanManager() = default;

std::shared_ptr<Loan> LoanManager::addLoan(int keyID, std::shared_ptr<Member> member, std::shared_ptr<Librarian> librarian, time_t timeOfLoan)
{
    if(!member->canLoan()) {
        std::cerr << "ERROR: This member has reached the loan limit !!!" << std::endl;
        return nullptr;
    }
    this->loan_list.emplace(keyID, std::make_shared<Loan>(keyID, member, librarian, timeOfLoan));
    
    member->increaseLoanCount();
    
    return this->loan_list.at(keyID);
}

std::shared_ptr<Loan> LoanManager::getLoan(int keyID)
{
    return this->loan_list.at(keyID);
}

bool LoanManager::isLoanKeyIdFree(int loanKeyID)
{
    for(auto l : this->loan_list) {
        if(l.second->getID() == loanKeyID) return false;
    }
    return true;
}

std::string LoanManager::toStr(int tabSize)
{
    std::stringstream ss;

    ss << tabs(tabSize) << "Loan Manager " << "{" << std::endl;

    for(auto l : loan_list) {
        ss << l.second->toStr(tabSize+1) << std::endl;
    }

    ss << tabs(tabSize) << "}";

    return ss.str();
}