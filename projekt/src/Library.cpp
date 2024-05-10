#include "inc/Library.h"

Library::Library(const std::string& libraryName)
    : libraryName(libraryName)
    , catalog(std::make_shared<Catalog>())
    , librarianManager(std::make_shared<LibrarianManager>())
    , loanManager(std::make_shared<LoanManager>())
    , memberManager(std::make_shared<MemberManager>())
{}

Library::~Library()
{}

// std::shared_ptr<Catalog> Library::getCatalog() const { return this->catalog; }
Catalog& Library::getCatalog() const { return *this->catalog; }

// std::shared_ptr<LibrarianManager> Library::getLibrarianManager() const { return this->librarianManager; }
LibrarianManager& Library::getLibrarianManager() const { return *this->librarianManager; }

// std::shared_ptr<LoanManager> Library::getLoanManager() const { return this->loanManager; }
LoanManager& Library::getLoanManager() const { return *this->loanManager; }

// std::shared_ptr<MemberManager> Library::getMemberManager() const { return this->memberManager; }
MemberManager& Library::getMemberManager() const { return *this->memberManager; }

Loan& Library::createLoan(int loanKeyID, int memberKeyID, int librarianKeyID, time_t timeOfLoan)
{
    if(!this->getLoanManager().isLoanKeyIdFree(loanKeyID)) {
        std::cerr << "ERROR: This loanKeyID: " << loanKeyID << " is not free!!!" << std::endl;
        throw nullptr;
    }
    
    std::shared_ptr<Member> member = this->getMemberManager().getMember(memberKeyID); 
    std::shared_ptr<Librarian> librarian = this->getLibrarianManager().getLibrarian(librarianKeyID);

    if(!member) {
        std::cerr << "ERROR: There is no Member with ID: " << memberKeyID << std::endl;
        throw nullptr;
    }

    if(!librarian) {
        std::cerr << "ERROR: There is no Librarian with ID: " << librarianKeyID << std::endl;
        throw nullptr;
    }

    if(!member->canLoan()) {
        std::cerr << "ERROR: This member " << "(" << memberKeyID << ")" << " has reached the loan limit!!!" << std::endl;
        throw nullptr;
    }

    this->getLoanManager().addLoan(loanKeyID, member, librarian, timeOfLoan);

    return *this->getLoanManager().getLoan(loanKeyID);
}

std::string Library::toStr(int tabSize)
{
    std::stringstream ss;
    ss << 
        tabs(tabSize) << this->libraryName << " :: Library " << "{" << std::endl << 
        tabs(tabSize) << this->catalog->toStr(1) << std::endl <<
        tabs(tabSize) << this->librarianManager->toStr(1) << std::endl <<
        tabs(tabSize) << this->memberManager->toStr(1) << std::endl <<
        tabs(tabSize) << this->loanManager->toStr(1) << std::endl <<
        tabs(tabSize) << "}";

    return ss.str();
}

void Library::printOut()
{
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << this->toStr(0) << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
}