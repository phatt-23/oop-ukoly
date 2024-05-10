#include "inc/Librarian.h"

int Librarian::objectCount = 0;

Librarian::Librarian(int salary, time_t timeOfEmployment, int ID, const std::string& forename, const std::string& surname)
    : Person(ID, forename, surname), salary(salary), dateOfEmployment(ctime(&timeOfEmployment))
{
    Librarian::objectCount++;
}

Librarian::~Librarian()
{
    Librarian::objectCount--;
}

std::string Librarian::toStr(int tabSize)
{
    std::string tmp = this->dateOfEmployment;
    tmp.erase(tmp.size() - 1);

    std::stringstream ss;

    ss << tabs(tabSize) << "Librarian " << "{" << std::endl <<
    tabs(tabSize+1) << "ID: " << this->getID()  << std::endl <<
    tabs(tabSize+1) << "Forename: " << this->getForename()  << std::endl <<
    tabs(tabSize+1) << "Surname: " << this->getSurname()  << std::endl <<
    tabs(tabSize+1) << "Salary: " << this->salary  << std::endl <<
    tabs(tabSize+1) << "Date: " << tmp  << std::endl <<
    tabs(tabSize) << "}";

    return ss.str();
}

int Librarian::getObjectCount()
{
    return Librarian::objectCount;
}