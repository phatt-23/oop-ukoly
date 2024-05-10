#include "inc/Catalog.h"

Catalog::Catalog()
{}

Catalog::~Catalog()
{}

const MobilePhone& Catalog::addProduct(int ID, int amount, int selfieCamera_MP, int simSlots, const std::string& name, Dim3 dimensions, Dim2 displayResolution, const std::string& platform, int mainCamera_MP, int battery_mAh, int memory_GB, int storage_GB)
{
    product_list.emplace(ID, std::make_tuple(std::make_shared<MobilePhone>(selfieCamera_MP, simSlots, name, dimensions, displayResolution, platform, mainCamera_MP, battery_mAh, memory_GB, storage_GB), amount));

    return static_cast<MobilePhone&>(*get<0>(product_list.at(ID)));
}
        
const Notebook& Catalog::addProduct(int ID, int amount, const std::string& keyboard, const std::string& touchpad, const std::string& name, Dim3 dimensions, Dim2 displayResolution, const std::string& platform, int mainCamera_MP, int battery_Wh, int memory_GB, int storage_GB)
{
    product_list.emplace(ID, std::make_tuple(std::make_shared<Notebook>(keyboard, touchpad, name, dimensions, displayResolution, platform, mainCamera_MP, battery_Wh, memory_GB, storage_GB), amount));

    return static_cast<Notebook&>(*get<0>(product_list.at(ID)));
}

const Tablet& Catalog::addProduct(int ID, int amount, int selfieCamera_MP, const std::string& name, Dim3 dimensions, Dim2 displayResolution, const std::string& platform, int mainCamera_MP, int battery_mAh, int memory_GB, int storage_GB)
{
    product_list.emplace(ID, std::make_tuple(std::make_shared<Tablet>(selfieCamera_MP, name, dimensions, displayResolution, platform, mainCamera_MP, battery_mAh, memory_GB, storage_GB), amount));

    return static_cast<Tablet&>(*get<0>(product_list.at(ID)));
}

const AbstractProduct& Catalog::addProduct(int ID, int amount, std::shared_ptr<AbstractProduct> product) 
{
    product_list.emplace(ID, std::make_tuple(std::move(product), amount));
    return *std::dynamic_pointer_cast<AbstractProduct>(product).get();
}

const AbstractProduct& Catalog::getProduct(int ID)
{
    return *std::dynamic_pointer_cast<AbstractProduct>(get<0>(product_list.at(ID))).get();
}

std::map<int, std::tuple<std::shared_ptr<AbstractProduct>, int>>& Catalog::getProductList() 
{
    return product_list;
}
