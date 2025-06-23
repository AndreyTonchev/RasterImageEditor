#pragma once

#include <iostream>
#include <vector>

#include "../Pixels/AbstractPixel.hpp"

/**
 * @class AbstractPixelMatrix
 * @brief Abstract base class for a 2D matrix of pixels used in image processing.
 * 
 * Provides an interface for manipulating and transforming pixel data.
 */
class AbstractPixelMatrix {
public:
    /**
     * @brief Virtual destructor for proper cleanup of derived classes.
     */
    virtual ~AbstractPixelMatrix() noexcept = default;

    /**
     * @brief Gets the width of the pixel matrix.
     * @return Width of the matrix in pixels.
     */
    virtual std::size_t getWidth() const = 0;

    /**
     * @brief Gets the height of the pixel matrix.
     * @return Height of the matrix in pixels.
     */
    virtual std::size_t getHeight() const = 0;

    /**
     * @brief Resizes the pixel matrix to new dimensions.
     * @param newWidth New width in pixels.
     * @param newHeight New height in pixels.
     */
    virtual void resize(std::size_t newWidth, std::size_t newHeight) = 0;

    /**
     * @brief Accesses a mutable pixel at the given position.
     * @param w Column index (width coordinate).
     * @param h Row index (height coordinate).
     * @return Pointer to the pixel at the given position.
     */
    virtual AbstractPixel* at(std::size_t w, std::size_t h) = 0;

    /**
     * @brief Accesses a constant pixel at the given position.
     * @param w Column index (width coordinate).
     * @param h Row index (height coordinate).
     * @return Const pointer to the pixel at the given position.
     */
    virtual const AbstractPixel* at(std::size_t w, std::size_t h) const = 0;

    /**
     * @brief Creates a deep copy of the current matrix.
     * @return A new AbstractPixelMatrix instance that is a copy of this one.
     */
    virtual AbstractPixelMatrix* clone() const = 0;

public:
    /**
     * @brief Prints the matrix in its default orientation (0 degrees rotation).
     * @param os Output stream to print to.
     */
    virtual void printR0(std::ostream& os = std::cout) const = 0;

    /**
     * @brief Prints the matrix rotated 90 degrees clockwise.
     * @param os Output stream to print to.
     */
    virtual void printR90(std::ostream& os = std::cout) const = 0;

    /**
     * @brief Prints the matrix rotated 180 degrees.
     * @param os Output stream to print to.
     */
    virtual void printR180(std::ostream& os = std::cout) const = 0;

    /**
     * @brief Prints the matrix rotated 270 degrees clockwise.
     * @param os Output stream to print to.
     */
    virtual void printR270(std::ostream& os = std::cout) const = 0;

    /**
     * @brief Prints the matrix mirrored horizontally.
     * @param os Output stream to print to.
     */
    virtual void printMH(std::ostream& os = std::cout) const = 0;

    /**
     * @brief Prints the matrix mirrored vertically.
     * @param os Output stream to print to.
     */
    virtual void printMV(std::ostream& os = std::cout) const = 0;

    /**
     * @brief Prints the matrix flipped across the main diagonal.
     * @param os Output stream to print to.
     */
    virtual void printDF(std::ostream& os = std::cout) const = 0;

    /**
     * @brief Prints the matrix flipped across the anti-diagonal.
     * @param os Output stream to print to.
     */
    virtual void printAD(std::ostream& os = std::cout) const = 0;

    /**
     * @brief Prints the matrix in its default orientation (0 degrees rotation).
     * @param os Output stream to print to.
     */
    virtual void printR0Binary(std::ostream& os = std::cout) const = 0;

    /**
     * @brief Prints the matrix rotated 90 degrees clockwise.
     * @param os Output stream to print to.
     */
    virtual void printR90Binary(std::ostream& os = std::cout) const = 0;

    /**
     * @brief Prints the matrix rotated 180 degrees.
     * @param os Output stream to print to.
     */
    virtual void printR180Binary(std::ostream& os = std::cout) const = 0;

    /**
     * @brief Prints the matrix rotated 270 degrees clockwise.
     * @param os Output stream to print to.
     */
    virtual void printR270Binary(std::ostream& os = std::cout) const = 0;

    /**
     * @brief Prints the matrix mirrored horizontally.
     * @param os Output stream to print to.
     */
    virtual void printMHBinary(std::ostream& os = std::cout) const = 0;

    /**
     * @brief Prints the matrix mirrored vertically.
     * @param os Output stream to print to.
     */
    virtual void printMVBinary(std::ostream& os = std::cout) const = 0;

    /**
     * @brief Prints the matrix flipped across the main diagonal.
     * @param os Output stream to print to.
     */
    virtual void printDFBinary(std::ostream& os = std::cout) const = 0;

    /**
     * @brief Prints the matrix flipped across the anti-diagonal.
     * @param os Output stream to print to.
     */
    virtual void printADBinary(std::ostream& os = std::cout) const = 0;

public:
    /**
     * @brief Applies a negative filter to the pixel matrix.
     */
    virtual void negative() = 0;

    /**
     * @brief Converts the pixel matrix to grayscale.
     */
    virtual void grayscale() = 0;

    /**
     * @brief Converts the pixel matrix to monochrome (black & white).
     */
    virtual void monochrome() = 0;

};
