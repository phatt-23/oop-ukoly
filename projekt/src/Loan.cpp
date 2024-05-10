#include "inc/Loan.h"

LoanItem::LoanItem(std::shared_ptr<LibraryItem> item)
    : item(item)
{}

LoanItem::~LoanItem() = default;

std::shared_ptr<LibraryItem> LoanItem::getItem() const
{
    return this->item;
}

std::string LoanItem::toStr(int tabSize)
{
    std::stringstream ss;

    auto book = dynamic_cast<Book*>(this->item.get());
    if(book) {
        // ss << book->toStr(tabSize);
        ss << tabs(tabSize) << "Book ID: " << book->getID();
    }
    
    auto dvd = dynamic_cast<DVD*>(this->item.get());
    if(dvd) {
        // ss << dvd->toStr(tabSize);
        ss << tabs(tabSize) << "DVD ID: " << dvd->getID();
    }

    return ss.str();
}

//
//
//

int Loan::objectCount = 0;

Loan::Loan(int ID, std::shared_ptr<Member> member, std::shared_ptr<Librarian> librarian, time_t timeOfLoan)
    : ID(ID), member(std::move(member)), librarian(std::move(librarian)), dateOfLoan(ctime(&timeOfLoan))
{
    Loan::objectCount++;
}

Loan::~Loan()
{
    Loan::objectCount--;
}

Loan& Loan::addItem(std::shared_ptr<LibraryItem> item)
{
    if(item->getNumberOfAvailableCopies() > 0) {
        item->decreaseNumberOfAvailableCopies();
        this->item_list.push_back(std::make_unique<LoanItem>(item));
    } else std::cerr << "ERROR: There is no copy left of " << "(" << item->getID() << ")" << std::endl;
    return *this;
}

Loan::LoanStatus Loan::getStatus() const
{
    return this->status;
}

void Loan::changeStatus(LoanStatus status)
{
    this->status = status;
}

int Loan::getID() const
{
    return this->ID;
}

int Loan::getObjectCount()
{
    return Loan::objectCount;
}


void Loan::returned()
{
    this->status = Returned;
    for(auto i : this->item_list) {
        i->getItem()->increaseNumberOfAvailableCopies();
    }
    this->member->decreaseLoanCount();
}

void Loan::overdue()
{
    this->status = Overdue;
}

void Loan::lost()
{
    this->status = Lost;
}


std::string Loan::toStr(int tabSize)
{
    std::string tmp = this->dateOfLoan;
    tmp.erase(tmp.end() - 1);

    std::stringstream ss;

    ss << 
    tabs(tabSize) << "Loan " << "{" << std::endl <<
    tabs(tabSize+1) << "ID: " << this->ID << std::endl <<
    tabs(tabSize+1) << "Member ID: " << this->member->getID() << std::endl <<
    tabs(tabSize+1) << "Librarian ID: " << this->librarian->getID() << std::endl <<
    tabs(tabSize+1) << "Status: " << ((this->status == Loaned) ? "Loaned" : ((this->status == Overdue) ? "Overdue" : "Returned")) << std::endl <<
    tabs(tabSize+1) << "Date: " << tmp << std::endl <<
    tabs(tabSize+1) << "Items: " << "{" << std::endl;

    for(auto i : item_list) {
        ss << i->toStr(tabSize+2) << std::endl;
    }

    ss << 
    tabs(tabSize+1) << "}" << std::endl << 
    tabs(tabSize) << "}";

    return ss.str();
}