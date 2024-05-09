#include "inc/Order.h"

OrderItem::OrderItem(AbstractStringOutput& product, int amount)
    : product(product), amount(amount)
{}

OrderItem::~OrderItem()
{
    if(__DEBUG) std::cout << __PRETTY_FUNCTION__ << std::endl;
}

std::string OrderItem::toString(int tab_amount) const
{
    std::stringstream ss;
    ss << tabs(tab_amount - 1) << 
    "{ " << std::endl << tabs(tab_amount) << 
    product.toString(tab_amount + 1) << ", " << std::endl << tabs(tab_amount) <<
    "\"amount\": " << amount << std::endl << tabs(tab_amount - 1) << 
    "}";
    return ss.str();
}

Order::Order(AbstractCustomer& customer)
    : customer(customer)
{}

Order::~Order()
{
    if(__DEBUG) std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Order& Order::addOrderItem(AbstractStringOutput& product, int amount)
{
    std::shared_ptr<OrderItem> orderItem = std::make_shared<OrderItem>(product, amount);
    item_list.push_back(orderItem);
    return *this;
}

Order& Order::addOrderItem(AbstractProduct& product, int amount)
{
    std::shared_ptr<OrderItem> orderItem = std::make_shared<OrderItem>(dynamic_cast<AbstractStringOutput&>(product), amount);
    item_list.push_back(orderItem);
    return *this;
}

std::vector<std::shared_ptr<OrderItem>>& Order::getItemList()
{
    return item_list;
}

std::string Order::toString(int tab_amount) const
{
    std::stringstream ss;
    ss <<
        "{ " << std::endl << tabs(tab_amount) <<
        "\"customer\": { " << std::endl << tabs(tab_amount + 1) << 
        dynamic_cast<AbstractStringOutput&>(customer).toString(tab_amount + 1) << std::endl << tabs(tab_amount) <<
        "\"items\": " << "[" << std::endl;
    for(size_t i = 0; i < item_list.size(); ++i) {
        ss << item_list[i]->toString(tab_amount + 2) << ((i < item_list.size() - 1) ? ", " : "");
        if(i < item_list.size() - 1) ss << std::endl;
    }
    ss << std::endl << tabs(tab_amount) <<
        "]" << std::endl << tabs(tab_amount - 1) << 
        "}";
    return ss.str();
}

void Order::print()
{}