#ifndef __LIBRARY_LIBRARIAN_H
#define __LIBRARY_LIBRARIAN_H

#include "Member.h"

class Librarian : public Person, StringOutput
{
    private:
        static int objectCount;

        int salary;
        std::string dateOfEmployment;

    public:
        Librarian(int salary, time_t timeOfEmployment, int ID, const std::string& forename, const std::string& surname);
        ~Librarian() override;

        std::string toStr(int tabSize) override;

        static int getObjectCount();
};

#endif//__LIBRARY_LIBRARIAN_H