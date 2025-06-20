#pragma once

#include <string>
#include <vector>

#include "../Image.hpp"
#include "ImageBase.hpp"

class ImageFactory {
public:
    static void registerImage(const std::string& name, const std::string& description, ImageBase* creator);
    static Image* create(const std::string& name, const std::string& filename);
private:
    struct ImageEntry {
        std::string name;
        std::string description;
        ImageBase* creator;
    }; 

    static std::vector<ImageEntry>& getRegistry();

};

