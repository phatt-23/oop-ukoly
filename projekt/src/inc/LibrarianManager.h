#ifndef __LIBRARY_LIBRARIAN_MANAGING_MODULE_H
#define __LIBRARY_LIBRARIAN_MANAGING_MODULE_H

#include "Librarian.h"
#include "StringOutput.h"

class LibrarianManager : public StringOutput
{
    private:
        std::map<int, std::shared_ptr<Librarian>> librarian_list;

    public:
        LibrarianManager();
        ~LibrarianManager();

/**
 * @brief Vector storing the sample librarians.
 * @param 0 int keyID, 
 * @param 1 const std::string& forename, 
 * @param 2 const std::string& surname
 * @param 3 int salary, 
 * @param 4 time_t timeOfEmployment, 
*/
        std::shared_ptr<Librarian> addLibrarian(
            int keyID, 
            const std::string& forename, 
            const std::string& surname,
            int salary, 
            time_t timeOfEmployment
        );

        std::shared_ptr<Librarian> getLibrarian(int keyID);

        std::string toStr(int tabSize) override;
};

#endif//__LIBRARY_LIBRARIAN_MANAGING_MODULE_H