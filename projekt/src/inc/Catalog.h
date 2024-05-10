#ifndef __LIBRARY_CATALOG_H
#define __LIBRARY_CATALOG_H

#include "Precomp.h"
#include "LibraryItem.h"
#include "StringOutput.h"

class Catalog : public StringOutput
{
    private:
        std::map<int, std::shared_ptr<LibraryItem>> item_list;

    public:
        Catalog();
        ~Catalog();

        /// Book(int numberOfPages, int editionYear, string editionDescription, int ID, const string name, string description, string author)
        /// DVD(int lengthInMinutes, bool audio, bool video, int ID, string name, string description, string author)
        std::shared_ptr<LibraryItem> addLibraryItem(int keyID, std::shared_ptr<LibraryItem> libraryItem);
        
        std::shared_ptr<Book> addBook(
            int keyID, 
            const std::string& name, 
            const std::string& author,
            const std::string& description, 
            const std::string& editionDescription, 
            int publicationYear, 
            int numberOfPages,
            int numberOfCopies
        );

        std::shared_ptr<DVD> addDVD(
            int keyID, 
            const std::string& name, 
            const std::string& author,
            const std::string& description, 
            bool audio, 
            bool video, 
            int lengthInMinutes,
            int numberOfCopies
        );

        std::shared_ptr<LibraryItem> getLibraryItem(int keyID);

        std::string toStr(int tabSize) override;
};

#endif//__LIBRARY_CATALOG_H