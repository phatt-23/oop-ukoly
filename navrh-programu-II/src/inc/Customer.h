#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Precomp.h"
#include "AbstractStringOutput.h"

class AbstractCustomer 
{
    protected:
        std::string contactEmail;
        std::string deliveryAddress; // all in one string

    public:
        AbstractCustomer(const std::string& contactEmail, const std::string& deliveryAddress);

        virtual ~AbstractCustomer();
};

class AbstractRegisteredCustomer : public AbstractCustomer
{
    protected:
        std::string username;
        std::string password;

    public:
        AbstractRegisteredCustomer(const std::string& username, const std::string& password, const std::string& contactEmail, const std::string& deliveryAddress);

        virtual ~AbstractRegisteredCustomer();
};

class CompanyUser : public AbstractRegisteredCustomer, public AbstractStringOutput
{
    private:
        std::string companyName;

    public:
        CompanyUser(const std::string& companyName, const std::string& username, const std::string& password, const std::string& contactEmail, const std::string& deliveryAddress);

        ~CompanyUser();

        virtual std::string toString(int tab_amount) const override;
};

class RegisteredUser : public AbstractRegisteredCustomer, public AbstractStringOutput
{
    private:
        std::string forename;
        std::string surname;

    public:
        RegisteredUser(const std::string& forename, const std::string& surname, const std::string& username, const std::string& password, const std::string& contactEmail, const std::string& deliveryAddress);

        ~RegisteredUser();

        virtual std::string toString(int tab_amount) const override;
};

class UnregisteredUser : public AbstractCustomer, public AbstractStringOutput
{
    private:
        std::string forename;
        std::string surname;

    public:
        UnregisteredUser(const std::string& forename, const std::string& surname, const std::string& contactEmail, const std::string& deliveryAddress);

        ~UnregisteredUser();

        virtual std::string toString(int tab_amount) const override;
};


#endif//CUSTOMER_H
