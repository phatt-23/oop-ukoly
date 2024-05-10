#ifndef __MEMBER_H
#define __MEMBER_H

#include "Precomp.h"
#include "StringOutput.h"
#include "Person.h"

class Member : public Person
{
    private:
        static int objectCount;

        int loanCount;

    public:
        Member(int ID, const std::string& forename, const std::string& surname);
        virtual ~Member() override;

        virtual bool canLoan() = 0;

        int getLoanCount() const;
        void setLoanCount(int loanCount);

        void increaseLoanCount();
        void decreaseLoanCount();

        static int getObjectCount();
};

class BasicMember : public Member, StringOutput
{
    private:
        static int objectCount;
        static int loanLimit; // 1
    
    public:
        BasicMember(int ID, const std::string& forename, const std::string& surname);
        virtual ~BasicMember() override;
        
        virtual std::string toStr(int tabSize) override;
        virtual bool canLoan() override;

        static int getObjectCount();
};

class PremiumMember : public BasicMember
{
    private:
        static int objectCount;
        static int loanLimit; // 3
        int bonusPoints;

    public:
        PremiumMember(int bonusPoints, int ID, const std::string& forename, const std::string& surname);
        ~PremiumMember() override;

        std::string toStr(int tabSize) override;
        bool canLoan() override;

        int getBonusPoints() const;
        void setBonusPoints(int bonusPoints);

        static int getObjectCount();
};

#endif//__MEMBER_H