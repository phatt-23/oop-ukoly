#ifndef ORDER_H
#define ORDER_H

#include "Precomp.h"
#include "Product.h"
#include "Customer.h"

class OrderItem : public AbstractStringOutput
{
    private:
        AbstractStringOutput& product;
        int amount;

    public:
        OrderItem(AbstractStringOutput& product, int amount);
        ~OrderItem();

        virtual std::string toString(int tab_amount) const override;
};

class Order : public AbstractStringOutput
{
    private:
        AbstractCustomer& customer;
        std::vector<std::shared_ptr<OrderItem>> item_list;

    public:
        Order(AbstractCustomer& customer);
        ~Order();

        Order& addOrderItem(AbstractStringOutput& product, int amount);
        Order& addOrderItem(AbstractProduct& product, int amount);
        
        std::vector<std::shared_ptr<OrderItem>>& getItemList();
        
        virtual std::string toString(int tab_amount) const override;

        void print();
};

#endif//ORDER_H