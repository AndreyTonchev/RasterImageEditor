#pragma once

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "../Pixels/AbstractPixel.hpp"
#include "AbstractPixelMatrix.hpp"
#include "../utils/Exceptions.hpp"
       

/**
 * @brief Enum representing image transformations.
 */
enum class Orientation {
    NONE = -1, ///< No orientation
    R0,        ///< Rotate 0°
    R90,       ///< Rotate 90°
    R180,      ///< Rotate 180°
    R270,      ///< Rotate 270°
    MH,        ///< Mirror Horizontally
    MV,        ///< Mirror Vertically
    DF,        ///< Diagonal Flip
    AD         ///< Anti-Diagonal Flip
};

/**
 * @class Image
 * @brief Abstract base class for a raster image.
 *
 * Represents the interface for an image composed of a pixel matrix,
 * supporting basic transformations and metadata access.
 */
class Image {
public:
    /**
     * @brief Default constructor.
     */
    Image();

    /**
     * @brief Copy constructor.
     * @param other The image to copy from.
     */
    Image(const Image& other);

    /**
     * @brief Assignment operator.
     * @param other The image to copy from.
     * @return Reference to the current object.
     */
    Image& operator=(const Image& other);

    /**
     * @brief Virtual destructor.
     */
    virtual ~Image() noexcept { delete pixels; };

    /**
     * @brief Creates a deep copy of the image.
     * @return A pointer to a new cloned Image object.
     */
    virtual Image* clone() const = 0;

    /**
     * @brief Gets the image width.
     * @return Width of the image.
     */
    std::size_t getWidth() const;

    /**
     * @brief Gets the image height.
     * @return Height of the image.
     */
    std::size_t getHeight() const;

    /**
     * @brief Gets the maximum pixel value.
     * @return Maximum value for a pixel.
     */
    std::size_t getMaxValue() const;

    /**
     * @brief Gets the filename associated with the image.
     * @return Image filename.
     */
    std::string getFilename() const;

    /**
     * @brief Get a mutable pixel at specified coordinates.
     * @param w Width coordinate.
     * @param h Height coordinate.
     * @return Pointer to the pixel.
     */
    virtual AbstractPixel* at(std::size_t w, std::size_t h);

    /**
     * @brief Get a read-only pixel at specified coordinates.
     * @param w Width coordinate.
     * @param h Height coordinate.
     * @return Const pointer to the pixel.
     */
    virtual const AbstractPixel* at(std::size_t w, std::size_t h) const;

    /**
     * @brief Resize the image dimensions.
     * @param newWidth New width in pixels.
     * @param newHeight New height in pixels.
     * @return True if successful.
     */
    bool resize(std::size_t newWidth, std::size_t newHeight);

    /**
     * @brief Print the Image to a file
     * @param os Output stream to print to.
     */
    virtual void print(std::ostream& os = std::cout) = 0;

    /**
     * @brief Print the pixel matrix of the image.
     * @param os Output stream to print to.
     */
    void printPixels(std::ostream& os = std::cout) const;

    /**
     * @brief Print dimensions of the image.
     * @param os Output stream to print to.
     */
    void printDimensions(std::ostream& os = std::cout) const;

    /**
     * @brief Apply a transformation to the image.
     * @param apply The orientation transformation to apply.
     */
    void transformOrientation(Orientation apply);

    /**
     * @brief Invert the pixel colors.
     */
    void negative();

    /**
     * @brief Convert image to grayscale.
     */
    void grayscale();

    /**
     * @brief Convert image to monochrome.
     */
    void monochrome();

    /**
     * @brief Save the image to a file.
     * @param filename The path to save the image to.
     */
    void save(const std::string& filename);

protected:
    std::string filename;              ///< Path and name of the file
    int height;                        ///< Image height
    int width;                         ///< Image width
    int maxValue;                      ///< Maximum pixel value
    Orientation orientation;           ///< Current orientation
    AbstractPixelMatrix* pixels;       ///< Pointer to pixel matrix

    static Orientation orientationTable[8][8]; ///< Orientation transformation lookup matrix
};
