#include "inc/Catalog.h"

Catalog::Catalog() = default;

Catalog::~Catalog() = default;

std::shared_ptr<LibraryItem> Catalog::addLibraryItem(int keyID, std::shared_ptr<LibraryItem> libraryItem)
{
    this->item_list.emplace(keyID, std::move(libraryItem));
    return libraryItem;
}

std::shared_ptr<Book> Catalog::addBook(int keyID, const std::string& name, const std::string& author,const std::string& description, const std::string& editionDescription, int publicationYear, int numberOfPages, int numberOfCopies)
{
    std::shared_ptr<Book> book = std::make_shared<Book>(numberOfPages, publicationYear, editionDescription, keyID, name, description, author, numberOfCopies);
    this->item_list.emplace(keyID, book);
    return book;
}

std::shared_ptr<DVD> Catalog::addDVD(int keyID, const std::string& name, const std::string& author,const std::string& description, bool audio, bool video, int lengthInMinutes, int numberOfCopies)
{
    return std::dynamic_pointer_cast<DVD>(this->item_list.emplace(keyID, std::make_shared<DVD>(lengthInMinutes, audio, video, keyID, name, description, author, numberOfCopies)).first->second);
}

std::shared_ptr<LibraryItem> Catalog::getLibraryItem(int keyID)
{
    return this->item_list.at(keyID);
}

std::string Catalog::toStr(int tabSize)
{
    std::stringstream ss;
    ss << tabs(tabSize) << "Catalog {" << std::endl;

    for(auto i : this->item_list) {
        auto iBook = dynamic_cast<Book*>(i.second.get()); 
        if(iBook) { // check if its a book
            ss << iBook->toStr(tabSize + 1) << std::endl;
        }

        auto iDVD = dynamic_cast<DVD*>(i.second.get()); 
        if(iDVD) { // check if its a DVD
            ss << iDVD->toStr(tabSize + 1) << std::endl;
        }
    }

    ss << tabs(tabSize) << "}";

    return ss.str();
}