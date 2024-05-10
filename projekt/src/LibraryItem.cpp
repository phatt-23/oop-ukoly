#include "inc/LibraryItem.h"

int LibraryItem::objectCount = 0;

LibraryItem::LibraryItem(long ID, const std::string& name, const std::string& description, const std::string& author, int numberOfCopies)
    : ID(ID), name(name), description(description), author(author), numberOfCopies(numberOfCopies), numberOfAvailableCopies(numberOfCopies)
{
    LibraryItem::objectCount++;
}

LibraryItem::~LibraryItem()
{
    LibraryItem::objectCount--;
}

long LibraryItem::getID() const
{
    return this->ID;
}

const std::string& LibraryItem::getName() const
{
    return this->name;
}

const std::string& LibraryItem::getDescription() const
{
    return this->description;
}

const std::string& LibraryItem::getAuthor() const
{
    return this->author;
}

int LibraryItem::getNumberOfCopies() const
{
    return this->numberOfCopies;
}

int LibraryItem::getNumberOfAvailableCopies() const
{
    return this->numberOfAvailableCopies;
}

void LibraryItem::setID(long ID)
{
    this->ID = ID;
}

void LibraryItem::setName(const std::string& name)
{
    this->name = name;
}

void LibraryItem::setDescription(const std::string& description)
{
    this->description = description;
}

void LibraryItem::setAuthor(const std::string& author)
{
    this->author = author;    
}

void LibraryItem::setNumberOfCopies(int numberOfCopies)
{
    this->numberOfCopies = numberOfCopies;
}

void LibraryItem::increaseNumberOfCopies()
{
    this->numberOfCopies++;
}

void LibraryItem::decreaseNumberOfCopies()
{
    this->numberOfCopies--;
}

void LibraryItem::increaseNumberOfAvailableCopies()
{
    this->numberOfAvailableCopies++;
}

void LibraryItem::decreaseNumberOfAvailableCopies()
{
    this->numberOfAvailableCopies--;
}


int LibraryItem::getObjectCount()
{
    return LibraryItem::objectCount;
}

int Book::objectCount = 0;

Book::Book(int numberOfPages, int publicationYear, const std::string& editionDescription, long ID, const std::string& name, const std::string& description, const std::string& author, int numberOfCopies)
    : LibraryItem(ID, name, description, author, numberOfCopies)
    , numberOfPages(numberOfPages)
    , publicationYear(publicationYear)
    , editionDescription(editionDescription)
{
    Book::objectCount++;
}

Book::~Book()
{
    Book::objectCount--;
}

int Book::getNumberOfPages() const
{
    return this->numberOfPages;
}

int Book::getPublicationYear() const
{
    return this->publicationYear;
}

const std::string& Book::getEditionDescription() const
{
    return this->editionDescription;
}

std::string Book::toStr(int tabSize)
{
    std::stringstream ss;

    int length = __DESCRIPTION_LENGTH;
    length = std::min(length, static_cast<int>(this->getDescription().length()));

    ss << 
    tabs(tabSize) << "Book {" << std::endl <<
    tabs(tabSize+1) << "ID: " << this->getID() << std::endl <<
    tabs(tabSize+1) << "Name: " << this->getName() << std::endl <<
    tabs(tabSize+1) << "Author: " << this->getAuthor() << std::endl <<
    tabs(tabSize+1) << "Description: " << this->getDescription().substr(0, length) << "..." << std::endl <<
    tabs(tabSize+1) << "Edition: " << this->editionDescription  << std::endl <<
    tabs(tabSize+1) << "Year: " << this->publicationYear << std::endl <<
    tabs(tabSize+1) << "Pages: " << this->numberOfPages << std::endl <<
    tabs(tabSize+1) << "Copies: " << this->getNumberOfAvailableCopies() << "/" << this->getNumberOfCopies() << std::endl <<
    tabs(tabSize) << "}";

    return ss.str();
}

int Book::getObjectCount()
{
    return Book::objectCount;
}

//
//
//

int DVD::objectCount = 0;

DVD::DVD(int lengthInMinutes, bool audio, bool video, long ID, const std::string& name, const std::string& description, const std::string& author, int numberOfCopies)
    : LibraryItem(ID, name, description, author, numberOfCopies)
    , lengthInMinutes(lengthInMinutes)
    , audio(audio)
    , video(video)
{
    DVD::objectCount++;
}

DVD::~DVD()
{
    DVD::objectCount--;
}

std::string DVD::toStr(int tabSize)
{
    std::stringstream ss;

    int length = __DESCRIPTION_LENGTH;
    length = std::min(length, static_cast<int>(this->getDescription().length()));

    ss <<
    tabs(tabSize) << "DVD " << "{" << std::endl <<
    tabs(tabSize+1) << "ID: " << this->getID() << std::endl <<
    tabs(tabSize+1) << "Name: " << this->getName() << std::endl <<
    tabs(tabSize+1) << "Author: " << this->getAuthor() << std::endl <<
    tabs(tabSize+1) << "Description: " << this->getDescription().substr(0, length) << "..." << std::endl <<
    tabs(tabSize+1) << "Audio: " << this->audio << std::endl <<
    tabs(tabSize+1) << "Video: " << this->video << std::endl <<
    tabs(tabSize+1) << "Length In Minutes: " << this->lengthInMinutes << std::endl <<
    tabs(tabSize+1) << "Copies: " << this->getNumberOfAvailableCopies() << "/" << this->getNumberOfCopies() << std::endl <<
    tabs(tabSize) << "}";
    
    return ss.str();
}

int DVD::getObjectCount()
{
    return DVD::objectCount;
}