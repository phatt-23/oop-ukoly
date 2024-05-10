#include "inc/Member.h"

int Member::objectCount = 0;

Member::Member(int ID, const std::string& forename, const std::string& surname)
    : Person(ID, forename, surname), loanCount(0)
{
    Member::objectCount++;
}

Member::~Member()
{
    Member::objectCount--;
}

int Member::getLoanCount() const
{
    return this->loanCount;
}

void Member::setLoanCount(int loanCount)
{
    this->loanCount = loanCount;
}

void Member::increaseLoanCount()
{
    this->loanCount++;
}

void Member::decreaseLoanCount()
{
    this->loanCount--;
}

int Member::getObjectCount()
{
    return Member::objectCount;
}

//
//

int BasicMember::objectCount = 0;
int BasicMember::loanLimit = 1; // 1

BasicMember::BasicMember(int ID, const std::string& forename, const std::string& surname)
    : Member(ID, forename, surname)
{
    BasicMember::objectCount++;
}

BasicMember::~BasicMember()
{
    BasicMember::objectCount--;
}
        
std::string BasicMember::toStr(int tabSize)
{
    std::stringstream ss;

    ss << 
    tabs(tabSize) << "Basic Member " << "{" << std::endl <<
    tabs(tabSize+1) << "ID: " << this->getID() << std::endl <<
    tabs(tabSize+1) << "Forename: " << this->getForename() << std::endl <<
    tabs(tabSize+1) << "Surname: " << this->getSurname() << std::endl <<
    tabs(tabSize+1) << "Loans: " << this->getLoanCount() << std::endl <<
    tabs(tabSize) << "}";

    return ss.str();
}

bool BasicMember::canLoan()
{
    return (this->getLoanCount() < BasicMember::loanLimit) ? true : false;
}

int BasicMember::getObjectCount()
{
    return BasicMember::objectCount;
}

int PremiumMember::objectCount = 0;
int PremiumMember::loanLimit = 3; // 3

PremiumMember::PremiumMember(int bonusPoints, int ID, const std::string& forename, const std::string& surname)
    : BasicMember(ID, forename, surname)
    , bonusPoints(bonusPoints)
{
    PremiumMember::objectCount++;
}

PremiumMember::~PremiumMember()
{
    PremiumMember::objectCount--;
}

std::string PremiumMember::toStr(int tabSize)
{
    std::stringstream ss;

    ss << 
    tabs(tabSize) << "Premium Member " << "{" << std::endl <<
    tabs(tabSize+1) << "ID: " << this->getID() << std::endl <<
    tabs(tabSize+1) << "Forename: " << this->getForename() << std::endl <<
    tabs(tabSize+1) << "Surname: " << this->getSurname() << std::endl <<
    tabs(tabSize+1) << "Loans: " << this->getLoanCount() << std::endl <<
    tabs(tabSize+1) << "Bonus Points: " << this->bonusPoints << std::endl <<
    tabs(tabSize) << "}";

    return ss.str();
}

bool PremiumMember::canLoan()
{
    return (this->getLoanCount() < PremiumMember::loanLimit) ? true : false;
}

int PremiumMember::getBonusPoints() const
{
    return this->bonusPoints;
}

void PremiumMember::setBonusPoints(int bonusPoints)
{
    this->bonusPoints = bonusPoints;
}

int PremiumMember::getObjectCount()
{
    return PremiumMember::objectCount;
}
