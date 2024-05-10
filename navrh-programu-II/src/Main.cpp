#include "inc/Shop.h"

int main() {
    // create the shop
    std::unique_ptr<Shop> shop = std::make_unique<Shop>("Eshop with Electornic Devices");
    
    // add products
    shop->getCatalog().addProduct(1, 100, std::make_shared<MobilePhone>(4, 1, "Huawei P20", (Dim3){8, 12, 3}, (Dim2){1920, 1280}, "Android", 12, 4500, 8, 128));
    shop->getCatalog().addProduct(2, 200, std::make_shared<MobilePhone>(4, 2, "iPhone XR", (Dim3){12, 45, 3}, (Dim2){1920, 1080}, "iOS", 20, 3200, 8, 256));
    shop->getCatalog().addProduct(3, 300, std::make_shared<Notebook>("Chiclet", "Precision 7760", "ThinkPad T16 Gen 2", (Dim3){361.9, 255.5, 20.5}, (Dim2){1980, 1200}, "Windows", 2, 52.5, 16, 2048));
    shop->getCatalog().addProduct(4, 200, std::make_shared<Tablet>(5, "Samsung Galaxy Tab A 12.1", (Dim3){245.2, 149.4, 7.5}, (Dim2){1920, 1200}, "Android", 8, 6150, 2, 16));

    // add customers
    shop->addCustomer(1, std::make_shared<RegisteredUser>("John", "Smith", "johnsmith123", "PaSsWoRd09", "john.smith09@mail.com", "Somewhere 12/43"));
    shop->addCustomer(2, std::make_shared<CompanyUser>("Some company", "some_company", "securepassword123*", "some.company@companymail.com", "Some Building 34"));
    shop->addCustomer(3, std::make_shared<UnregisteredUser>("Anonymní", "Uživatel", "anon@email.com", "Some Adress 34/56"));

    // make orders - ability to chain the addition of the products to each order
    shop->addOrder(1, shop->getCustomer(1))
        .addOrderItem(shop->getProduct(2), 13)
        .addOrderItem(shop->getProduct(3), 14)
        .addOrderItem(shop->getProduct(1), 12);

    shop->addOrder(2, shop->getCustomer(2))
        .addOrderItem(shop->getProduct(1), 2)
        .addOrderItem(shop->getProduct(2), 3)
        .addOrderItem(shop->getProduct(3), 4)
        .addOrderItem(shop->getProduct(4), 5);

    shop->addOrder(3, shop->getCustomer(3))
        .addOrderItem(shop->getProduct(4), 10)
        .addOrderItem(shop->getProduct(3), 30)
        .addOrderItem(shop->getProduct(2), 20)
        .addOrderItem(shop->getProduct(1), 10);

    // print the result in a semi-json format
    shop->print();

    return 0;
}