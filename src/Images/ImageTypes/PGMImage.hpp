/**
 * @file PGMImage.hpp
 * @brief Declares the PGMImage class for handling PGM image files (P2 ASCII and P5 binary formats).
 *
 * The PGM image format stores grayscale pixel data.
 * Supported formats:
 * - P2: ASCII encoding of pixels.
 * - P5: Binary encoding of pixels.
 *
 * File structure:
 * - Signature (P2 or P5)
 * - Width (unsigned int)
 * - Height (unsigned int)
 * - max_value (maximum pixel value)
 * - List of pixels (grayscale values ranging from 0 (black) to max_value (white))
 */

#pragma once

#include "../Image.hpp"
#include "../ImageFactory/ImageRegistrar.hpp"

/**
 * @enum PGMSignature
 * @brief Enum representing the PGM image format signature.
 */
enum class PGMSignature {
    NONE = -1, ///< Undefined or invalid signature
    P2,        ///< ASCII PGM format
    P5,        ///< Binary PGM format
};

/**
 * @class PGMImage
 * @brief Handles loading, storing, and printing of PGM grayscale images.
 *
 * Inherits from the Image base class and supports cloning, printing,
 * and loading PGM images in both ASCII (P2) and binary (P5) formats.
 */
class PGMImage : public Image {
public:
    /**
     * @brief Default constructor.
     */
    PGMImage();

    /**
     * @brief Constructs a PGMImage by loading from a file.
     * @param filename The path to the PGM image file.
     */
    PGMImage(const std::string& filename);

    /**
     * @brief Creates a polymorphic copy of this image.
     * @return A pointer to a new PGMImage copy.
     */
    inline virtual Image* clone() const override { return new PGMImage(*this); }

    /**
     * @brief Saves image information to the specified output stream.
     * @param os Output stream, defaults to std::cout.
     */
    virtual void save(const std::string& filename) override;

private:
    PGMSignature signature; ///< Stores the PGM signature (P2 or P5).

    /**
     * @brief Loads the image from a P2 ASCII PGM stream.
     * @param is Input stream to read from.
     */
    void loadP2File(std::istream& is);

    /**
     * @brief Loads the image from a P5 binary PGM stream.
     * @param is Input stream to read from.
     */
    void loadP5File(std::istream& is);

private:
    /**
     * @enum Channels
     * @brief Represents grayscale channel index.
     */
    enum Channels {
        GRAY ///< Grayscale channel index
    };
};

/**
 * @brief Registers the PGMImage type in the image factory.
 */
