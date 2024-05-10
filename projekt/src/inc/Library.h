#ifndef __LIBRARY_LIBRARY_H
#define __LIBRARY_LIBRARY_H

#include "Member.h"
#include "Catalog.h"
#include "LibrarianManager.h"
#include "LoanManager.h"
#include "MemberManager.h"

class Library : public StringOutput
{
    private:
        std::string libraryName;
        std::shared_ptr<Catalog> catalog;
        std::shared_ptr<LibrarianManager> librarianManager;
        std::shared_ptr<LoanManager> loanManager;
        std::shared_ptr<MemberManager> memberManager;

    public:
        Library(const std::string& libraryName);
        ~Library();

        // std::shared_ptr<Catalog> getCatalog() const;
        Catalog& getCatalog() const;

        // std::shared_ptr<LibrarianManager> getLibrarianManager() const;
        LibrarianManager& getLibrarianManager() const;

        // std::shared_ptr<LoanManager> getLoanManager() const;
        LoanManager& getLoanManager() const;
        
        // std::shared_ptr<MemberManager> getMemberManager() const;
        MemberManager& getMemberManager() const;

        Loan& createLoan(int loanKeyID, int memberKeyID, int librarianKeyID, time_t timeOfLoan);

        std::string toStr(int tabSize) override;
        void printOut();
};

#endif//__LIBRARY_LIBRARY_H