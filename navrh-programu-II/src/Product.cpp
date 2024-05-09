#include "inc/Product.h"

std::string Dim2::convertToString() const
{
    std::stringstream ret;
    ret << std::fixed << std::setprecision(2) << std::fixed << "\"x\": " << x << ", " << "\"y\": " << y;
    return ret.str();
}

std::string Dim3::convertToString() const
{
    std::stringstream ret;
    ret << std::fixed << std::setprecision(2) << "\"x\": " << x << ", " << "\"y\": " << y << ", " << "\"z\": " << z;
    return ret.str();
}

AbstractProduct::AbstractProduct(const std::string& name, Dim3 dimensions, Dim2 displayResolution, const std::string& platform, int mainCamera_MP, int battery, int memory_GB, int storage_GB)
    : name(name)
    , dimensions(dimensions)
    , displayResolution(displayResolution)
    , platform(platform)
    , mainCamera_MP(mainCamera_MP)
    , battery(battery)
    , memory_GB(memory_GB)
    , storage_GB(storage_GB)
{}

AbstractProduct::~AbstractProduct()
{}

MobilePhone::MobilePhone(int selfieCamera_MP, int simSlots, const std::string& name, Dim3 dimensions, Dim2 displayResolution, const std::string& platform, int mainCamera_MP, int battery_mAh, int memory_GB, int storage_GB)
    : AbstractProduct(name, dimensions, displayResolution, platform, mainCamera_MP, battery_mAh, memory_GB, storage_GB)
    , selfieCamera_MP(selfieCamera_MP)
    , simSlots(simSlots)
{}

MobilePhone::~MobilePhone()
{}

std::string MobilePhone::toString(int tab_amount) const
{
    std::stringstream ret;
    ret << "(MobilePhone): { " << std::endl << tabs(tab_amount) <<
        "\"selfie_camera_MP\": " << selfieCamera_MP << ", " << std::endl << tabs(tab_amount) <<
        "\"sim_slots\": " << simSlots << ", " << std::endl << tabs(tab_amount) <<
        "\"name\": " << "\"" << name << "\"" << ", " << std::endl << tabs(tab_amount) <<
        "\"dimensions\": " << "{ " << dimensions.convertToString() << " }" << ", " << std::endl << tabs(tab_amount) <<
        "\"display_resolution\": " << "{ " << displayResolution.convertToString() << " }" << ", " << std::endl << tabs(tab_amount) <<
        "\"platform\": " << "\"" << platform << "\"" << ", " << std::endl << tabs(tab_amount) <<
        "\"main_camera_MP\": " << mainCamera_MP << ", " << std::endl << tabs(tab_amount) <<
        "\"battery_mAh\": " << battery << ", " << std::endl << tabs(tab_amount) <<
        "\"memory_GB\": " << memory_GB << ", " << std::endl << tabs(tab_amount) <<
        "\"storage_GB\": " << storage_GB << std::endl << tabs(tab_amount - 1) <<
        "}";
    return ret.str();
}

Notebook::Notebook(const std::string& keyboard, const std::string& touchpad, const std::string& name, Dim3 dimensions, Dim2 displayResolution, const std::string& platform, int mainCamera_MP, int battery_mAh, int memory_GB, int storage_GB)
    : AbstractProduct(name, dimensions, displayResolution, platform, mainCamera_MP, battery_mAh, memory_GB, storage_GB)
    , keyboard(keyboard)
    , touchpad(touchpad)
{}

Notebook::~Notebook()
{}

std::string Notebook::toString(int tab_amount) const
{
    std::stringstream ret;
    ret << "(Notebook): { " << std::endl << tabs(tab_amount) <<
        "keyboard: " << keyboard << ", " << std::endl << tabs(tab_amount) <<
        "touchpad: " << touchpad << ", " << std::endl << tabs(tab_amount) <<
        "name: " << name << ", " << std::endl << tabs(tab_amount) <<
        "dimensions: " << "{ " << dimensions.convertToString() << " }" << ", " << std::endl << tabs(tab_amount) <<
        "display_resolution: " << "{ " << displayResolution.convertToString() + " }" << ", " << std::endl << tabs(tab_amount) <<
        "platform: " << platform << ", " << std::endl << tabs(tab_amount) <<
        "main_camera_MP: " << mainCamera_MP << ", " << std::endl << tabs(tab_amount) <<
        "battery_Wh: " << battery << ", " << std::endl << tabs(tab_amount) <<
        "memory_GB: " << memory_GB << ", " << std::endl << tabs(tab_amount) <<
        "storage_GB: " << storage_GB << std::endl << tabs(tab_amount - 1) <<
        "}";
    return ret.str();
}

Tablet::Tablet()
    : AbstractProduct("default", {1, 2, 3}, {1, 2}, "default", 1, 1, 1, 1)
{}

Tablet::Tablet(int selfieCamera_MP, const std::string& name, Dim3 dimensions, Dim2 displayResolution, const std::string& platform, int mainCamera_MP, int battery_mAh, int memory_GB, int storage_GB)
    : AbstractProduct(name, dimensions, displayResolution, platform, mainCamera_MP, battery_mAh, memory_GB, storage_GB)
    , selfieCamera_MP(selfieCamera_MP)
{}

Tablet::~Tablet()
{}

std::string Tablet::toString(int tab_amount) const
{
    std::stringstream ret;
    ret << std::fixed << "(Tablet): { " << std::endl << tabs(tab_amount) <<
        "\"selfie_camera_MP\": " << selfieCamera_MP << ", " <<  std::endl << tabs(tab_amount) <<
        "\"name\": " << "\"" << name << "\"" << ", " << std::endl << tabs(tab_amount) <<
        "\"dimensions\": { " << dimensions.convertToString() << " }" << ", " << std::endl << tabs(tab_amount) <<
        "\"display_dimensions\": { " << displayResolution.convertToString() << " }" << ", " << std::endl << tabs(tab_amount) <<
        "\"platform\": " << "\"" << platform << "\"" << ", " << std::endl << tabs(tab_amount) <<
        "\"main_camera_MP\": " << mainCamera_MP << ", " << std::endl << tabs(tab_amount) <<
        "\"battery_mAh\": " << battery << ", " << std::endl << tabs(tab_amount) <<
        "\"memory_GB\": " << memory_GB << ", " << std::endl << tabs(tab_amount) <<
        "\"storage_GB\": " << storage_GB << std::endl << tabs(tab_amount - 1) <<
        "}";
    return ret.str();
}
    // ret << "(MobilePhone): { " << 
    //     "\"selfie_camera_MP\": " << selfieCamera_MP << ", " <<
    //     "\"sim_slots\": " << simSlots << ", " <<
    //     "\"name\": " << "\"" << name << "\"" << ", " <<
    //     "\"dimensions\": " << "{ " << dimensions.convertToString() << " }" << ", " <<
    //     "\"display_resolution\": " << "{ " << displayResolution.convertToString() << " }" << ", " <<
    //     "\"platform\": " << "\"" << platform << "\"" << ", " <<
    //     "\"main_camera_MP\": " << mainCamera_MP << ", " <<
    //     "\"battery_mAh\": " << battery << ", " <<
    //     "\"memory_GB\": " << memory_GB << ", " <<
    //     "\"storage_GB\": " << storage_GB << " }";

    // ret << "(Notebook): { " << 
    //     "keyboard: " << keyboard << ", " <<
    //     "touchpad: " << touchpad << ", " <<
    //     "name: " << name << ", " <<
    //     "dimensions: " << "{ " << dimensions.convertToString() << " }" << ", " <<
    //     "display_resolution: " << "{ " << displayResolution.convertToString() + " }" << ", " <<
    //     "platform: " << platform << ", " <<
    //     "main_camera_MP: " << mainCamera_MP << ", " <<
    //     "battery_Wh: " << battery << ", " <<
    //     "memory_GB: " << memory_GB << ", " <<
    //     "storage_GB: " << storage_GB << " }";

    // ret << std::fixed << "(Tablet): { " << 
    //     "\"selfie_camera_MP\": " << selfieCamera_MP << ", " << 
    //     "\"name\": " << "\"" << name << "\"" << ", " <<
    //     "\"dimensions\": { " << dimensions.convertToString() << " }" << ", " <<
    //     "\"display_dimensions\": { " << displayResolution.convertToString() << " }" << ", " <<
    //     "\"platform\": " << "\"" << platform << "\"" << ", " <<
    //     "\"main_camera_MP\": " << mainCamera_MP << ", " <<
    //     "\"battery_mAh\": " << battery << ", " <<
    //     "\"memory_GB\": " << memory_GB << ", " <<
    //     "\"storage_GB\": " << storage_GB << " }";
