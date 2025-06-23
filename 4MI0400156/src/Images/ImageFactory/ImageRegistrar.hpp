#pragma once

#include <string>

#include "ImageBase.hpp"
#include "ImageFactory.hpp"

/**
 * @brief Template class to register image format handlers with the ImageFactory.
 * 
 * This class acts as a registrar that automatically registers a given image type
 * with the factory upon construction. It inherits from ImageBase and provides
 * a create method to instantiate images of the registered type.
 * 
 * @tparam T The image class type that must have a constructor accepting a filename.
 */
template <typename T>
class ImageRegistrar : public ImageBase {
public:
    /**
     * @brief Constructs an ImageRegistrar and registers the image type.
     * 
     * Registers the image format by its extension (name) and description
     * with the ImageFactory. The registrar instance itself is passed as the factory creator.
     * 
     * @param name The file extension or name representing the image format (e.g., "ppm").
     * @param description A human-readable description of the image format.
     */
    ImageRegistrar(const std::string& name, const std::string& description);

    /**
     * @brief Creates an Image instance from a filename.
     * 
     * Overrides the abstract create method from ImageBase to instantiate
     * the image type T using the filename.
     * 
     * @param filename The path or name of the image file to load.
     * @return Pointer to a new instance of image type T.
     */
    Image* create(const std::string& filename) const;
};


template <typename T>
ImageRegistrar<T>::ImageRegistrar(const std::string& name, const std::string& description) {
    ImageFactory::registerImage(name, description, this);
}

template <typename T>
Image* ImageRegistrar<T>::create(const std::string& filename) const {
    return new T(filename);
}
