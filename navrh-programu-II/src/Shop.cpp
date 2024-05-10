#include "inc/Shop.h"

Shop::Shop(const std::string& shopName)
    : shopName(shopName)
    , catalog(std::make_unique<Catalog>())
{}
        
Shop::~Shop()
{
    if(__DEBUG) std::cout << __PRETTY_FUNCTION__ << std::endl;
}

const CompanyUser& Shop::addCustomer(int ID, const std::string& companyName, const std::string& username, const std::string& password, const std::string& contactEmail, const std::string& deliveryAddress)
{
    customer_list.emplace(ID, std::make_shared<CompanyUser>(companyName, username, password, contactEmail, deliveryAddress));
    return static_cast<CompanyUser&>(*customer_list.at(ID).get());
}

const RegisteredUser& Shop::addCustomer(int ID, const std::string& forename, const std::string& surname, const std::string& username, const std::string& password, const std::string& contactEmail, const std::string& deliveryAddress)
{
    customer_list.emplace(ID, std::make_shared<RegisteredUser>(forename, surname, username, password, contactEmail, deliveryAddress));
    return static_cast<RegisteredUser&>(*customer_list.at(ID).get());
}

const UnregisteredUser& Shop::addCustomer(int ID, const std::string& forename, const std::string& surname, const std::string& contactEmail, const std::string& deliveryAddress)
{
    customer_list.emplace(ID, std::make_shared<UnregisteredUser>(forename, surname, contactEmail, deliveryAddress));
    return static_cast<const UnregisteredUser&>(*customer_list.at(ID).get());
}

const AbstractCustomer& Shop::addCustomer(int ID, std::shared_ptr<AbstractCustomer> customer)
{
    customer_list.emplace(ID, customer);
    return *customer.get();
}

Order& Shop::addOrder(int ID, AbstractCustomer& customer)
{
    order_list.emplace(ID, std::make_shared<Order>(customer));
    return *order_list.at(ID).get();
}

Order& Shop::addOrder(int ID, int customerID)
{
    order_list.emplace(ID, std::make_shared<Order>(getCustomer(customerID)));
    return *order_list.at(ID).get();
}

const OrderItem& Shop::addOrderItemToOrder(Order& order, AbstractProduct& product, const int amount)
{
    order.addOrderItem(dynamic_cast<AbstractStringOutput&>(product), amount);
    return *order.getItemList().back();
}

const OrderItem& Shop::addOrderItemToOrder(int orderID, int productID, int amount)
{
    order_list.at(orderID)->addOrderItem(*std::get<0>(catalog->getProductList().at(productID)).get(), amount);
    return *order_list.at(orderID)->getItemList().back();
}

AbstractCustomer& Shop::getCustomer(int ID)
{
    return dynamic_cast<AbstractCustomer&>(*customer_list.at(ID).get());
}
        
AbstractProduct& Shop::getProduct(int ID)
{
    return *std::dynamic_pointer_cast<AbstractProduct>(std::get<0>(catalog->getProductList().at(ID)));
}

Order& Shop::getOrder(int ID)
{
    return *order_list.at(ID).get();
}

Catalog& Shop::getCatalog()
{
    return *catalog;
}

std::string Shop::toString(int tab_amount) const
{
    (void) tab_amount;
    std::stringstream ss;
    ss << tabs(0) << "{" << std::endl;
    ss << tabs(1) << "\"shopname:\" " << "\"" << shopName << "\"" << std::endl;
    ss << tabs(1) << "\"content:\" {" << std::endl;
    ss << tabs(2) << "Catalog: [" << std::endl;
    size_t i = 0;
    for(const auto& product : catalog->getProductList()) {
        ss << tabs(3) << "product_" << product.first << " " << dynamic_cast<AbstractStringOutput*>(std::get<0>(product.second).get())->toString(4) << ((i++ < catalog->getProductList().size() - 1) ? "," : "") << std::endl;
    }
    ss << tabs(2) << "]," << std::endl;
    ss << tabs(2) << "Customers: [" << std::endl;
    i = 0;
    for(const auto& customer : customer_list) {
        ss << tabs(3) << "customer_" << customer.first << " " << dynamic_cast<AbstractStringOutput*>(customer.second.get())->toString(4) << ((i++ < customer_list.size() - 1) ? "," : "") << std::endl;
    }
    ss << tabs(2) << "]," << std::endl;
    ss << tabs(2) << "Orders: [" << std::endl;
    i = 0;
    for(auto order : order_list) {
        std::cout << tabs(3) << "order_" << order.first << ": " << order.second->toString(4) << ((i++ < order_list.size() - 1) ? "," : "") << std::endl;
    }
    ss << tabs(2) << "]" << std::endl;
    ss << tabs(1) << "}" << std::endl;
    ss << tabs(0) << "}" << std::endl;
    return ss.str();
}

void Shop::print()
{
    std::cout << tabs(0) << "{" << std::endl;
    std::cout << tabs(1) << "\"shopname:\" " << "\"" << shopName << "\"" << std::endl;
    std::cout << tabs(1) << "\"content:\" {" << std::endl;
    std::cout << tabs(2) << "Catalog: [" << std::endl;
    size_t i = 0;
    for(const auto& product : catalog->getProductList()) {
        std::cout << tabs(3) << "product_" << product.first << " " << dynamic_cast<AbstractStringOutput*>(std::get<0>(product.second).get())->toString(4) << ((i++ < catalog->getProductList().size() - 1) ? "," : "") << std::endl;
    }
    std::cout << tabs(2) << "]," << std::endl;
    std::cout << tabs(2) << "Customers: [" << std::endl;
    i = 0;
    for(const auto& customer : customer_list) {
        std::cout << tabs(3) << "customer_" << customer.first << " " << dynamic_cast<AbstractStringOutput*>(customer.second.get())->toString(4) << ((i++ < customer_list.size() - 1) ? "," : "") << std::endl;
    }
    std::cout << tabs(2) << "]," << std::endl;
    std::cout << tabs(2) << "Orders: [" << std::endl;
    i = 0;
    for(auto order : order_list) {
        std::cout << tabs(3) << "order_" << order.first << ": " << order.second->toString(4) << ((i++ < order_list.size() - 1) ? "," : "") << std::endl;
    }
    std::cout << tabs(2) << "]" << std::endl;
    std::cout << tabs(1) << "}" << std::endl;
    std::cout << tabs(0) << "}" << std::endl;
}

