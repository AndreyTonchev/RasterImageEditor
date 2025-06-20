#pragma once

#include <string>
#include <vector>

#include "../Image.hpp"
#include "ImageBase.hpp"

class ImageFactory {
public:
    static void registerImage(const std::string& extension, const std::string& description, ImageBase* creator);
    static Image* create(const std::string& extension, const std::string& filename);
    static std::string getImageDescription(const std::string& extension);
private:
    struct ImageEntry {
        std::string extension;
        std::string description;
        ImageBase* creator;
    }; 

    static std::vector<ImageEntry>& getRegistry();

};

