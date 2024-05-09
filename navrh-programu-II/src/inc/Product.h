#ifndef PRODUCT_H
#define PRODUCT_H

#include "Precomp.h"
#include "AbstractStringOutput.h"

struct Dim2 { double x, y;    std::string convertToString() const; };
struct Dim3 { double x, y, z; std::string convertToString() const; };

class AbstractProduct
{
    protected:
        std::string name;
        Dim3 dimensions;
        Dim2 displayResolution;
        std::string platform;
        int mainCamera_MP;
        int battery;
        int memory_GB;
        int storage_GB;

    public:
        AbstractProduct(const std::string& name, Dim3 dimensions, Dim2 displayResolution, const std::string& platform, int mainCamera_MP, int battery, int memory_GB, int storage_GB);

        virtual ~AbstractProduct();
};

class MobilePhone : public AbstractProduct, public AbstractStringOutput
{
    private:
        int selfieCamera_MP;
        int simSlots;

    public:
        MobilePhone(int selfieCamera_MP, int simSlots, const std::string& name, Dim3 dimensions, Dim2 displayResolution, const std::string& platform, int mainCamera_MP, int battery_mAh, int memory_GB, int storage_GB);

        ~MobilePhone();

        virtual std::string toString(int tab_amount) const override;
};

class Notebook : public AbstractProduct, public AbstractStringOutput
{
    private:
        std::string keyboard;
        std::string touchpad;

    public:
        Notebook(const std::string& keyboard, const std::string& touchpad, const std::string& name, Dim3 dimensions, Dim2 displayResolution, const std::string& platform, int mainCamera_MP, int battery_Wh, int memory_GB, int storage_GB);

        ~Notebook();

        virtual std::string toString(int tab_amount) const override;
};

class Tablet : public AbstractProduct, public AbstractStringOutput
{
    private:
        int selfieCamera_MP;

    public:
        Tablet();
        Tablet(int selfieCamera_MP, const std::string& name, Dim3 dimensions, Dim2 displayResolution, const std::string& platform, int mainCamera_MP, int battery_mAh, int memory_GB, int storage_GB);

        ~Tablet();

        virtual std::string toString(int tab_amount) const override;
};

#endif//PRODUCT_H