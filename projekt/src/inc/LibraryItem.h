#ifndef __LIBRARY__ITEM_H
#define __LIBRARY__ITEM_H

#include "Precomp.h"
#include "StringOutput.h"

class LibraryItem
{
    public:
        enum Tag { Basic, Premium };

    private:
        static int objectCount;

        long ID;
        std::string name;
        std::string description;
        std::string author;
        int numberOfCopies;
        int numberOfAvailableCopies;


    public:
        LibraryItem(long ID, const std::string& name, const std::string& description, const std::string& author, int numberOfCopies);
        virtual ~LibraryItem();

        long getID() const;
        const std::string& getName() const;
        const std::string& getDescription() const;
        const std::string& getAuthor() const;
        int getNumberOfCopies() const;
        int getNumberOfAvailableCopies() const;

        void setID(long ID);
        void setName(const std::string& name);
        void setDescription(const std::string& description);
        void setAuthor(const std::string& author);
        void setNumberOfCopies(int numberOfCopies);

        void increaseNumberOfAvailableCopies();
        void decreaseNumberOfAvailableCopies();

        void increaseNumberOfCopies();
        void decreaseNumberOfCopies();

        static int getObjectCount();
};

class Book : public LibraryItem, StringOutput
{
    private:
        static int objectCount;

        int numberOfPages;
        int publicationYear;
        std::string editionDescription;

    public:
        Book(int numberOfPages, int publicationYear, const std::string& editionDescription, long ID, const std::string& name, const std::string& description, const std::string& author, int numberOfCopies);
        ~Book() override;

        int getNumberOfPages() const;
        int getPublicationYear() const;
        const std::string& getEditionDescription() const;

        std::string toStr(int tabSize) override;

        static int getObjectCount();
};

class DVD : public LibraryItem, StringOutput
{
    private:
        static int objectCount;
    
        int lengthInMinutes;
        bool audio;
        bool video;
    
    public:
        DVD(int lengthInMinutes, bool audio, bool video, long ID, const std::string& name, const std::string& description, const std::string& author, int numberOfCopies);
        ~DVD() override;

        std::string toStr(int tabSize) override;

        static int getObjectCount();
};

#endif//__LIBRARY__ITEM_H