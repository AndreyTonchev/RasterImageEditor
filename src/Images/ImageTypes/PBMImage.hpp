/**
 * @file PBMImage.hpp
 * @brief Declares the PBMImage class for handling PBM image files (P1 ASCII and P4 binary formats).
 *
 * The PBM image format stores black and white (monochrome) pixel data.
 * Supported formats:
 * - P1: ASCII encoding of pixels.
 * - P4: Binary encoding of pixels.
 *
 * File structure:
 * - Signature (P1 or P4)
 * - Width (unsigned int)
 * - Height (unsigned int)
 * - List of pixels (each pixel is either 0 for black or 1 for white)
 */

#pragma once

#include "../Image.hpp"

/**
 * @enum PBMSignature
 * @brief Enum representing the PBM image format signature.
 */
enum class PBMSignature {
    NONE = -1, ///< Undefined or invalid signature
    P1,        ///< ASCII PBM format
    P4,        ///< Binary PBM format
};

/**
 * @class PBMImage
 * @brief Handles loading, storing, and printing of PBM black-and-white images.
 *
 * Inherits from the Image base class and supports cloning, printing,
 * and loading PBM images in both ASCII (P1) and binary (P4) formats.
 */
class PBMImage : public Image {
public:
    /**
     * @brief Default constructor.
     */
    PBMImage();

    /**
     * @brief Constructs a PBMImage by loading from a file.
     * @param filename The path to the PBM image file.
     */
    PBMImage(const std::string& filename);

    /**
     * @brief Creates a polymorphic copy of this image.
     * @return A pointer to a new PBMImage copy.
     */
    inline virtual Image* clone() const override { return new PBMImage(*this); }

    /**
     * @brief Prints image information to the specified output stream.
     * @param os Output stream, defaults to std::cout.
     */
    virtual void print(std::ostream& os = std::cout) override;

private:
    PBMSignature signature; ///< Stores the PBM signature (P1 or P4).

    /**
     * @brief Loads the image from a P1 ASCII PBM stream.
     * @param is Input stream to read from.
     */
    void loadP1File(std::istream& is);

    /**
     * @brief Loads the image from a P4 binary PBM stream.
     * @param is Input stream to read from.
     */
    void loadP4File(std::istream& is);
};
