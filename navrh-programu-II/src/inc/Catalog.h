#ifndef CATALOG_H
#define CATALOG_H

#include "Precomp.h"
#include "Product.h"

class Catalog
{
    private:
        std::map<int, std::tuple<std::shared_ptr<AbstractProduct>, int>> product_list;
    
    public:
        Catalog();
        ~Catalog();

        const MobilePhone& addProduct(int ID, int amount, int selfieCamera_MP, int simSlots, const std::string& name, Dim3 dimensions, Dim2 displayResolution, const std::string& platform, int mainCamera_MP, int battery_mAh, int memory_GB, int storage_GB);
        
        const Notebook& addProduct(int ID, int amount, const std::string& keyboard, const std::string& touchpad, const std::string& name, Dim3 dimensions, Dim2 displayResolution, const std::string& platform, int mainCamera_MP, int battery_mAh, int memory_GB, int storage_GB);

        const Tablet& addProduct(int ID, int amount, int selfieCamera_MP, const std::string& name, Dim3 dimensions, Dim2 displayResolution, const std::string& platform, int mainCamera_MP, int battery_mAh, int memory_GB, int storage_GB);

        const AbstractProduct& addProduct(int ID, int amount, std::shared_ptr<AbstractProduct> product);

        const AbstractProduct& getProduct(int ID);

        std::map<int, std::tuple<std::shared_ptr<AbstractProduct>, int>>& getProductList();
};

#endif//CATALOG_H