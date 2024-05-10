#include "inc/Library.h"
#include "inc/SampleData.h"

int main() 
{
    // Creating a Library
    std::unique_ptr<Library> lib = std::make_unique<Library>("Some Normal Library");

    // Loading data into my Library from SampleData.h
    for(const auto& b : books) {
        auto [keyID, name, author, desc, editionDesc, publicationYear, numberOfPages, numberOfCopies] = b;
        lib->getCatalog().addBook(keyID, name, author, desc, editionDesc, publicationYear, numberOfPages, numberOfCopies);
    }

    for(const auto& d : dvds) {
        auto [keyID, name, author, desc, audio, video, lengthInMinutes, numberOfCopies] = d;
        lib->getCatalog().addDVD(keyID, name, author, desc, audio, video, lengthInMinutes, numberOfCopies);
    }

    for(const auto& l : librarians) {
        auto [keyID, forename, surname, salary, timeOfEmployment] = l;
        lib->getLibrarianManager().addLibrarian(keyID, forename, surname, salary, timeOfEmployment);
    }

    for(const auto& bm : bmembers) {
        auto [keyID, forename, surname] = bm;
        lib->getMemberManager().addBasicMember(keyID, forename, surname);
    }

    for(const auto& pm : pmembers) {
        auto [keyID, forename, surname, bonusPoints] = pm;
        lib->getMemberManager().addPremiumMember(keyID, forename, surname, bonusPoints);
    }
    
    // Creating some Loans
    lib->createLoan(400000, 300000, 200000, time(nullptr))
        .addItem(lib->getCatalog().getLibraryItem(100000))
        .addItem(lib->getCatalog().getLibraryItem(100000))  // writes out ERROR message
        .addItem(lib->getCatalog().getLibraryItem(100002));
        
    lib->createLoan(400001, 310000, 200001, time(nullptr))
        .addItem(lib->getCatalog().getLibraryItem(110000))
        .addItem(lib->getCatalog().getLibraryItem(110002));

    lib->createLoan(400002, 300001, 200003, time(nullptr))
        .addItem(lib->getCatalog().getLibraryItem(100001))
        .addItem(lib->getCatalog().getLibraryItem(110001));

    lib->createLoan(400003, 300003, 200002, time(nullptr))
        .addItem(lib->getCatalog().getLibraryItem(100002))
        .addItem(lib->getCatalog().getLibraryItem(110001)); 

    lib->getLoanManager().getLoan(400001)->returned();
    lib->getLoanManager().getLoan(400002)->overdue();
    lib->getLoanManager().getLoan(400003)->lost();

    lib->printOut();

    return 0;
}