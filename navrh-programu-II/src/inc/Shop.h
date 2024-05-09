#ifndef SHOP_H
#define SHOP_H

#include "Order.h"
#include "Catalog.h"

class Shop : public AbstractStringOutput
{
    private:
        std::string shopName;
        std::map<int, std::shared_ptr<Order>> order_list;
        std::map<int, std::shared_ptr<AbstractStringOutput>> customer_list;
        std::unique_ptr<Catalog> catalog;

    public:
        Shop(const std::string& shopName);
        
        ~Shop();

        const CompanyUser& addCustomer(int ID, const std::string& companyName, const std::string& username, const std::string& password, const std::string& contactEmail, const std::string& deliveryAddress);

        const RegisteredUser& addCustomer(int ID, const std::string& forename, const std::string& surname, const std::string& username, const std::string& password, const std::string& contactEmail, const std::string& deliveryAddress);

        const UnregisteredUser& addCustomer(int ID, const std::string& forename, const std::string& surname, const std::string& contactEmail, const std::string& deliveryAddress); 

        const AbstractCustomer& addCustomer(int ID, std::shared_ptr<AbstractStringOutput> customer);

        Order& addOrder(int ID, AbstractCustomer& customer);

        Order& addOrder(int ID, int customerID);

        const OrderItem& addOrderItemToOrder(Order& order, AbstractStringOutput& product, const int amount);

        const OrderItem& addOrderItemToOrder(Order& order, AbstractProduct& product, int amount);

        const OrderItem& addOrderItemToOrder(int orderID, int productID, int amount);

        AbstractCustomer& getCustomer(int ID);
        
        AbstractProduct& getProduct(int ID);

        Order& getOrder(int ID);

        Catalog& getCatalog();

        virtual std::string toString(int tab_amount) const override;

        void print();
};

#endif//SHOP_H