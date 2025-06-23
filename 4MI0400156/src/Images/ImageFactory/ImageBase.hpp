// ImageBase.hpp
#pragma once

#include "../Image.hpp"

/**
 * @brief Abstract base class for image creation factories.
 * 
 * Provides an interface for creating Image objects from filenames.
 * Used as a base for registering specific image format creators.
 */
class ImageBase {
public:
    /**
     * @brief Virtual destructor for proper cleanup of derived classes.
     */
    virtual ~ImageBase() = default;

    /**
     * @brief Creates an Image object from a given filename.
     * 
     * @param filename The name or path of the image file to load.
     * @return Pointer to a newly created Image instance.
     */
    virtual Image* create(const std::string& filename) const = 0;
};
