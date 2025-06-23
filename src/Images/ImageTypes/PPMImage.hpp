/**
 * @file PPMImage.hpp
 * @brief Declares the PPMImage class for handling PPM image files (P3 ASCII and P6 binary formats).
 *
 * The PPM image format stores pixel data as triplets of red, green, and blue values.
 * Supported formats:
 * - P3: ASCII encoding of pixels.
 * - P6: Binary encoding of pixels.
 *
 * File structure:
 * - Signature (P3 or P6)
 * - Width (unsigned int)
 * - Height (unsigned int)
 * - max_value (maximum pixel value)
 * - List of pixels (triplets of RGB values ranging from 0 to max_value)
 */

#pragma once

#include "../Image.hpp"

/**
 * @enum PPMSignature
 * @brief Enum to represent the PPM image format signature.
 */
enum class PPMSignature {
    NONE = -1, ///< Undefined or invalid signature
    P3,        ///< ASCII PPM format
    P6,        ///< Binary PPM format
};

/**
 * @class PPMImage
 * @brief Handles loading, storing, and printing of PPM images.
 *
 * Inherits from the base Image class and supports cloning, printing,
 * and loading PPM images in both ASCII (P3) and binary (P6) formats.
 */
class PPMImage : public Image {
public:
    /**
     * @brief Default constructor for PPMImage.
     */
    PPMImage();

    /**
     * @brief Constructs a PPMImage by loading from a file.
     * @param filename The path to the PPM image file.
     */
    PPMImage(const std::string& filename);

    /**
     * @brief Creates a polymorphic copy of this image.
     * @return A pointer to a new PPMImage copy.
     */
    inline virtual Image* clone() const override { return new PPMImage(*this); }

    /**
     * @brief Prints image information to the specified output stream.
     * @param os Output stream, defaults to std::cout.
     */
    virtual void print(std::ostream& os = std::cout) override;

    /**
     * @brief Default destructor.
     */
    virtual ~PPMImage() = default;

private:
    PPMSignature signature; ///< Stores the PPM signature (P3 or P6).

    /**
     * @brief Loads the image from a P3 ASCII PPM stream.
     * @param is Input stream to read from.
     */
    void loadP3File(std::istream& is);

    /**
     * @brief Loads the image from a P6 binary PPM stream.
     * @param is Input stream to read from.
     */
    void loadP6File(std::istream& is);

    void saveP6File(std::ostream& os);

private:
    /**
     * @enum Channels
     * @brief Color channels for the PPM format.
     */
    enum Channels {
        RED,   ///< Red channel index
        GREEN, ///< Green channel index
        BLUE,  ///< Blue channel index
    };
};
