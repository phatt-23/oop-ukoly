#include "inc/Customer.h"

AbstractCustomer::AbstractCustomer(const std::string& contactEmail, const std::string& deliveryAddress)
    : contactEmail(contactEmail), deliveryAddress(deliveryAddress)
{}

AbstractCustomer::~AbstractCustomer()
{
    if(__DEBUG) std::cout << __PRETTY_FUNCTION__ << std::endl;
}

AbstractRegisteredCustomer::AbstractRegisteredCustomer(const std::string& username, const std::string& password, const std::string& contactEmail, const std::string& deliveryAddress)
    : AbstractCustomer(contactEmail, deliveryAddress)
    , username(username)
    , password(password) 
{}

AbstractRegisteredCustomer::~AbstractRegisteredCustomer()
{
    if(__DEBUG) std::cout << __PRETTY_FUNCTION__ << std::endl;
}

CompanyUser::CompanyUser(const std::string& companyName, const std::string& username, const std::string& password, const std::string& contactEmail, const std::string& deliveryAddress)
    : AbstractRegisteredCustomer(username, password, contactEmail, deliveryAddress)
    , companyName(companyName)
{}

CompanyUser::~CompanyUser()
{
    if(__DEBUG) std::cout << __PRETTY_FUNCTION__ << std::endl;
}

std::string CompanyUser::toString(int tab_amount) const
{
    std::stringstream ss;
    ss << "(CompanyUser): " << "{ " << std::endl << tabs(tab_amount) <<
        "\"company_name\": " << "\"" << companyName << "\"" <<  ", " <<std::endl << tabs(tab_amount) <<
        "\"username\": " << "\"" << username << "\"" << ", " <<std::endl << tabs(tab_amount) <<
        "\"password\": " << "\"" << password << "\"" <<  ", " <<std::endl << tabs(tab_amount) <<
        "\"contact_email\": " << "\"" << contactEmail << "\"" << ", " << std::endl << tabs(tab_amount) <<
        "\"delivery_address\": " << "\"" << deliveryAddress << "\"" << std::endl << tabs(tab_amount - 1) <<
        "}";

    return ss.str();
}

RegisteredUser::RegisteredUser(const std::string& forename, const std::string& surname, const std::string& username, const std::string& password, const std::string& contactEmail, const std::string& deliveryAddress)
    : AbstractRegisteredCustomer(username, password, contactEmail, deliveryAddress)
    , forename(forename)
    , surname(surname)
{}

RegisteredUser::~RegisteredUser()
{
    if(__DEBUG) std::cout << __PRETTY_FUNCTION__ << std::endl;
}

std::string RegisteredUser::toString(int tab_amount) const
{
    std::stringstream ss;
    ss << "(RegisteredCustomer): " << "{ " << std::endl << tabs(tab_amount) <<
        "\"forename\": " << "\"" << forename << "\"" << ", " <<std::endl << tabs(tab_amount) <<
        "\"surname\": " << "\"" << surname << "\"" << ", " <<std::endl << tabs(tab_amount) <<
        "\"username\": " << "\"" << username << "\"" << ", " <<std::endl << tabs(tab_amount) <<
        "\"password\": " << "\"" << password << "\"" << ", " <<std::endl << tabs(tab_amount) <<
        "\"contact_email\": " << "\"" << contactEmail << "\"" << ", " << std::endl << tabs(tab_amount) <<
        "\"delivery_address\": " << "\"" << deliveryAddress << "\"" << std::endl << tabs(tab_amount - 1) <<
        "}";

    return ss.str();
}

UnregisteredUser::UnregisteredUser(const std::string& forename, const std::string& surname, const std::string& contactEmail, const std::string& deliveryAddress)
    : AbstractCustomer(contactEmail, deliveryAddress)
    , forename(forename)
    , surname(surname)
{}

UnregisteredUser::~UnregisteredUser()
{
    if(__DEBUG) std::cout << __PRETTY_FUNCTION__ << std::endl;
}

std::string UnregisteredUser::toString(int tab_amount) const
{
    std::stringstream ss;
    ss << "(UnregisteredCustomer): " << "{ " << std::endl << tabs(tab_amount) <<
        "\"forename\": " << "\"" << forename << "\"" << ", " << std::endl << tabs(tab_amount) <<
        "\"surname\": " << "\"" << surname << "\"" << ", " << std::endl << tabs(tab_amount) <<
        "\"contact_email\": " << "\"" << contactEmail << "\"" << ", " << std::endl << tabs(tab_amount) <<
        "\"delivery_address\": " << "\"" << deliveryAddress << "\"" << std::endl << tabs(tab_amount - 1) <<
        "}";

    return ss.str();
}
