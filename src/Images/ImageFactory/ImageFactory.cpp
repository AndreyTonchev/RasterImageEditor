#include "ImageFactory.hpp"


std::vector<ImageFactory::ImageEntry>& ImageFactory::getRegistry() {
    static std::vector<ImageEntry> registry;
    return registry;
}

void ImageFactory::registerImage(const std::string& extension, const std::string& description, ImageBase* creator) {
    getRegistry().push_back({ extension, description, creator });
}

Image* ImageFactory::create(const std::string& extension, const std::string& filename) {
    std::vector<ImageEntry>& registry = getRegistry();

    for (std::size_t i = 0; i < registry.size(); ++i) {
        const ImageEntry& entry = registry[i];
        if (entry.extension == extension) {
            return entry.creator->create(filename);
        }
    }

    return nullptr;
}

std::string ImageFactory::getImageDescription(const std::string& extension) {
    std::vector<ImageEntry>& registry = getRegistry();
    for (int i = 0; i < registry.size(); i++) {
        if (extension == registry[i].extension) {
            return registry[i].description;
        }
    }

    return "No information found";
}
