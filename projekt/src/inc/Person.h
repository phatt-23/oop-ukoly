#ifndef __GENERIC_PERSON_H
#define __GENERIC_PERSON_H

#include "Precomp.h"

class Person
{
    private:
        int ID;
        std::string forename;
        std::string surname;
    
    public:
        Person(int ID, const std::string& forename, const std::string& surname);
        virtual ~Person() = 0;

        int getID() const;
        const std::string& getForename() const;
        const std::string& getSurname() const;

        void setID(int ID);
        void setForename(const std::string& forename);
        void setSurname(const std::string& surname);
};

#endif//__GENERIC_PERSON_H