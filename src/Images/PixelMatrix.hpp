#pragma once

#include <iostream>
#include <vector>
#include <cmath>

#include "Image.hpp"
#include "../Pixels/TemplatePixel.hpp"
#include "../utils/Exceptions.hpp"

/**
 * @class PixelMatrix
 * @brief Templated concrete implementation of AbstractPixelMatrix for storing and manipulating 2D pixel grids.
 * 
 * @tparam PixelType A class derived from AbstractPixel that implements pixel behavior.
 */
template <typename PixelType>
class PixelMatrix : public AbstractPixelMatrix {
public:
    /**
     * @brief Constructs a PixelMatrix with the given dimensions and maximum pixel value.
     * 
     * @param width Width of the image.
     * @param height Height of the image.
     * @param maxValue Maximum pixel value (for color depth).
     */
    PixelMatrix(std::size_t width, std::size_t height, std::size_t maxValue);

    /**
     * @brief Returns the width of the pixel matrix.
     * @return Matrix width.
     */
    virtual std::size_t getWidth() const override;

    /**
     * @brief Returns the height of the pixel matrix.
     * @return Matrix height.
     */
    virtual std::size_t getHeight() const override;

    /**
     * @brief Resizes the pixel matrix to new dimensions, preserving overlapping pixels.
     * 
     * @param newWidth New width.
     * @param newHeight New height.
     */
    virtual void resize(std::size_t newWidth, std::size_t newHeight) override;

    /**
     * @brief Provides mutable access to the pixel at the given position.
     * 
     * @param w Column index.
     * @param h Row index.
     * @return Pointer to the pixel.
     */
    virtual AbstractPixel* at(std::size_t w, std::size_t h) override;

    /**
     * @brief Provides constant access to the pixel at the given position.
     * 
     * @param w Column index.
     * @param h Row index.
     * @return Const pointer to the pixel.
     */
    virtual const AbstractPixel* at(std::size_t w, std::size_t h) const override;

    /**
     * @brief Clones the pixel matrix (deep copy).
     * @return Pointer to the new PixelMatrix object.
     */
    virtual AbstractPixelMatrix* clone() const override;

public:
    /**
     * @brief Prints the matrix in its original orientation (0°).
     * @param os Output stream.
     */
    virtual void printR0(std::ostream& os = std::cout) const override;

    /**
     * @brief Prints the matrix rotated 90° clockwise.
     * @param os Output stream.
     */
    virtual void printR90(std::ostream& os = std::cout) const override;

    /**
     * @brief Prints the matrix rotated 180°.
     * @param os Output stream.
     */
    virtual void printR180(std::ostream& os = std::cout) const override;

    /**
     * @brief Prints the matrix rotated 270° clockwise.
     * @param os Output stream.
     */
    virtual void printR270(std::ostream& os = std::cout) const override;

    /**
     * @brief Prints the matrix mirrored horizontally.
     * @param os Output stream.
     */
    virtual void printMH(std::ostream& os = std::cout) const override;

    /**
     * @brief Prints the matrix mirrored vertically.
     * @param os Output stream.
     */
    virtual void printMV(std::ostream& os = std::cout) const override;

    /**
     * @brief Prints the matrix flipped across the main diagonal.
     * @param os Output stream.
     */
    virtual void printDF(std::ostream& os = std::cout) const override;

    /**
     * @brief Prints the matrix flipped across the anti-diagonal.
     * @param os Output stream.
     */
    virtual void printAD(std::ostream& os = std::cout) const override;

public:
    /**
     * @brief Applies a negative filter to all pixels.
     */
    virtual void negative() override;

    /**
     * @brief Converts all pixels to grayscale.
     */
    virtual void grayscale() override;

    /**
     * @brief Converts all pixels to monochrome (black or white).
     */
    virtual void monochrome() override;

private:
    int width;          ///< Width of the matrix.
    int height;         ///< Height of the matrix.
    int maxValue;       ///< Maximum color value.
    std::vector<std::vector<PixelType>> pixels; ///< 2D container of pixels.
};

template <typename PixelType>
PixelMatrix<PixelType>::PixelMatrix(std::size_t width, std::size_t height, std::size_t maxValue)
    : width(width), height(height), maxValue(maxValue), pixels(height, std::vector<PixelType>(width)) {
}

template <typename PixelType>
std::size_t PixelMatrix<PixelType>::getHeight() const {
    return height;
}

template <typename PixelType>
std::size_t PixelMatrix<PixelType>::getWidth() const {
    return width;
}

template <typename PixelType>
void PixelMatrix<PixelType>::resize(std::size_t newWidth, std::size_t newHeight) {
    std::vector<std::vector<PixelType>> newPixels(newHeight, std::vector<PixelType>(newWidth));

    std::size_t minWidth = (width > newWidth) ?
        newWidth : width;

    std::size_t minHeight = (height > newHeight) ?
        newHeight : height;


    for (std::size_t y = 0; y < minHeight; ++y) {
        for (std::size_t x = 0; x < minWidth; ++x) {
            newPixels[y][x] = pixels[y][x];
        }
    }

    PixelType blank;

    for (std::size_t y = 0; y < newHeight; ++y) {
        for (std::size_t x = 0; x < newWidth; ++x) {
            if (y >= height || x >= width) {
                newPixels[y][x] = blank;
            }
        }
    }

    pixels = std::move(newPixels);
    width = newWidth;
    height = newHeight;
}

template <typename PixelType>
AbstractPixelMatrix* PixelMatrix<PixelType>::clone() const {
    return new PixelMatrix<PixelType>(*this);
}

template <typename PixelType>
const AbstractPixel* PixelMatrix<PixelType>::at(std::size_t w, std::size_t h) const {
    if (h >= height || w >= width) {
        throw FormatException("PixelMatrix::at() index out of range");
    }
    return &pixels[h][w];
}
    
template <typename PixelType>
AbstractPixel* PixelMatrix<PixelType>::at(std::size_t w, std::size_t h) {
    if (h >= height || w >= width) {
        throw FormatException("PixelMatrix::at() index out of range");
    }
    return &pixels[h][w];
}

template <typename PixelType>
void PixelMatrix<PixelType>::negative() {
    for (std::size_t y = 0; y < height; y++) {
        for (std::size_t x = 0; x < width; x++) {
            pixels[y][x].negative(maxValue);
        }
    }
}

template <typename PixelType>
void PixelMatrix<PixelType>::monochrome() {
    for (std::size_t y = 0; y < height; y++) {
        for (std::size_t x = 0; x < width; x++) {
            pixels[y][x].monochrome(maxValue);
        }
    }
}

template <typename PixelType>
void PixelMatrix<PixelType>::grayscale() {
    for (std::size_t y = 0; y < height; y++) {
        for (std::size_t x = 0; x < width; x++) {
            pixels[y][x].grayscale(maxValue);
        }
    }
}

template <typename PixelType>
void PixelMatrix<PixelType>::printR0(std::ostream& os) const {
    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            pixels[h][w].print(os);
        }
        os << std::endl;
    } 
}

template <typename PixelType>
void PixelMatrix<PixelType>::printR90(std::ostream& os) const {
    for (int w = 0; w < width; w++) {
        for (int h = height - 1; h >= 0; h--) {
            pixels[h][w].print(os);
        }
        os << std::endl;
    }
}

template <typename PixelType>
void PixelMatrix<PixelType>::printR180(std::ostream& os) const {
    for (int h = height - 1; h >= 0; h--) {
        for (int w = width - 1 ; w >= 0; w--) {
            pixels[h][w].print(os);
        }
        os << std::endl;
    }
}

template <typename PixelType>
void PixelMatrix<PixelType>::printR270(std::ostream& os) const {
    for (int w = width - 1; w >= 0; w--) {
        for (int h = 0; h < height; h++) {
            pixels[h][w].print(os);
        }
        os << std::endl;
    }
}

template <typename PixelType>
void PixelMatrix<PixelType>::printMH(std::ostream& os) const {
    for (int h = 0; h < height; h++) {
        for (int w = width - 1; w >= 0; w--) {
            pixels[h][w].print(os);
        }
        os << std::endl;
    }
}

template <typename PixelType>
void PixelMatrix<PixelType>::printMV(std::ostream& os) const {
    for (int h = height - 1; h >= 0; h--) {
        for (int w = 0; w < width; w++) {
            pixels[h][w].print(os);
        }
        os << std::endl;
    }
}

template <typename PixelType>
void PixelMatrix<PixelType>::printDF(std::ostream& os) const {
    for (int w = 0; w < width; w++) {
        for (int h = 0; h < height; h++) {
            pixels[h][w].print(os);
        }
        os << std::endl;
    }
}

template <typename PixelType>
void PixelMatrix<PixelType>::printAD(std::ostream& os) const {
    for (int w = width - 1; w >= 0; w--) {
        for (int h = height - 1; h >= 0; h--) {
            pixels[h][w].print(os);
        }
        os << std::endl;
    }
}