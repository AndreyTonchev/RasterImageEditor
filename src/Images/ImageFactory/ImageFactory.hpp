// ImageFactory.hpp
#pragma once

#include <string>
#include <vector>

#include "../Image.hpp"
#include "ImageBase.hpp"

/**
 * @brief Factory class for managing image format registrations and creation.
 * 
 * Allows registration of image loaders by file extension and delegates creation
 * of Image objects to the appropriate registered creator.
 */
class ImageFactory {
public:
    /**
     * @brief Registers a new image format handler.
     * 
     * Associates a file extension with a description and a factory object that
     * can create Images of that type.
     * 
     * @param extension File extension (e.g., "ppm", "pbm") to register.
     * @param description Human-readable description of the image format.
     * @param creator Pointer to an ImageBase-derived factory that creates images of this type.
     */
    static void registerImage(const std::string& extension, const std::string& description, ImageBase* creator);

    /**
     * @brief Creates an Image object based on the registered file extension.
     * 
     * Looks up the creator associated with the extension and uses it to create
     * an Image from the provided filename.
     * 
     * @param extension File extension indicating the image type.
     * @param filename Path or name of the image file.
     * @return Pointer to the created Image object, or nullptr if no creator registered.
     */
    static Image* create(const std::string& extension, const std::string& filename);

    /**
     * @brief Retrieves the description of a registered image format.
     * 
     * @param extension File extension to query.
     * @return The human-readable description associated with the extension,
     * or an empty string if not registered.
     */
    static std::string getImageDescription(const std::string& extension);

private:
    /**
     * @brief Structure to hold registration information for each image format.
     */
    struct ImageEntry {
        std::string extension;   ///< File extension (e.g., "ppm").
        std::string description; ///< Description of the image format.
        ImageBase* creator;      ///< Factory pointer to create images of this format.
    };

    /**
     * @brief Internal registry storing all registered image formats.
     * 
     * @return Reference to the static vector holding ImageEntry records.
     */
    static std::vector<ImageEntry>& getRegistry();
};
