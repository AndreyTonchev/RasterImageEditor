#include "ImageFactory.hpp"


std::vector<ImageFactory::ImageEntry>& ImageFactory::getRegistry() {
    static std::vector<ImageEntry> registry;
    return registry;
}

void ImageFactory::registerImage(const std::string& name, const std::string& description, ImageBase* creator) {
    getRegistry().push_back({ name, description, creator });
}

Image* ImageFactory::create(const std::string& name, const std::string& filename) {
    std::vector<ImageEntry>& registry = getRegistry();

    for (std::size_t i = 0; i < registry.size(); ++i) {
        const ImageEntry& entry = registry[i];
        if (entry.name == name) {
            return entry.creator->create(filename);
        }
    }

    return nullptr;
}
