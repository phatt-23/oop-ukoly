#include "inc/Person.h"

Person::Person(int ID, const std::string& forename, const std::string& surname)
    : ID(ID), forename(forename), surname(surname)
{}

Person::~Person()
{}

int Person::getID() const
{
    return this->ID;
}

const std::string& Person::getForename() const
{
    return this->forename;
}

const std::string& Person::getSurname() const
{
    return this->surname;
}

void Person::setID(int ID)
{
    this->ID = ID;
}

void Person::setForename(const std::string& forename)
{
    this->forename = forename;
}

void Person::setSurname(const std::string& surname)
{
    this->surname = surname;
}