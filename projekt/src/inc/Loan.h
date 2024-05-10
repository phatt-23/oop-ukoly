#ifndef __LOAN_H
#define __LOAN_H

#include "Precomp.h"
#include "LibraryItem.h"
#include "Member.h"
#include "Librarian.h"

class LoanItem : public StringOutput
{
    private:
        std::shared_ptr<LibraryItem> item; // gets its own copy of the Item

    public:
        LoanItem(std::shared_ptr<LibraryItem> item);
        ~LoanItem();

        std::shared_ptr<LibraryItem> getItem() const;

        std::string toStr(int tabSize) override;
};

class Loan : public StringOutput
{
    public:
        enum LoanStatus { Loaned, Overdue, Returned, Lost };

    private:
        static int objectCount;
        int ID;
        std::shared_ptr<Member> member;
        std::shared_ptr<Librarian> librarian;
        LoanStatus status;
        std::string dateOfLoan;         // [https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm]
        std::vector<std::shared_ptr<LoanItem>> item_list;

    public:
        Loan(int ID, std::shared_ptr<Member> member, std::shared_ptr<Librarian> librarian, time_t timeOfLoan); 
        ~Loan();

        Loan& addItem(std::shared_ptr<LibraryItem> item);

        LoanStatus getStatus() const;

        void changeStatus(LoanStatus status);

        static int getObjectCount();

        int getID() const;

        void returned();

        void overdue();

        void lost();

        std::string toStr(int tabSize) override;
};

#endif//__LOAN_H