#pragma once

#include <iostream>
#include <memory>

/**
 * @brief Abstract interface representing a generic pixel.
 * 
 * Supports operations like channel access, printing, cloning, and basic image transformations.
 */
class AbstractPixel {
public:
    /**
     * @brief Virtual destructor for safe polymorphic deletion.
     */
    virtual ~AbstractPixel() = default;
    
    /**
     * @brief Create a deep copy of this pixel.
     * 
     * @return A pointer to the newly cloned pixel.
     */
    virtual AbstractPixel* clone() const = 0;

    /**
     * @brief Set the value of a given channel.
     * 
     * @param channel Index of the channel to set.
     * @param value The new value for the channel.
     */
    virtual void setChannel(size_t channel, uint32_t value) = 0;

    /**
     * @brief Get the value of a given channel.
     * 
     * @param channel Index of the channel to retrieve.
     * @return The value of the specified channel.
     */
    virtual uint32_t getChannel(size_t channel) const = 0;

    /**
     * @brief Print the pixel's channel values to the given output stream.
     * 
     * @param os The output stream to print to (defaults to std::cout).
     */
    virtual void print(std::ostream& os = std::cout) const = 0;

    /**
     * @brief Copy channel data from another pixel of the same type.
     * 
     * @param other Pointer to the source pixel.
     */
    virtual void copyFrom(const AbstractPixel* other) = 0;

    /**
     * @brief Convert the pixel to its negative using a given maximum value.
     * 
     * @param maxValue The maximum channel value (e.g., 255).
     */
    virtual void negative(int maxValue) = 0;

    /**
     * @brief Convert the pixel to monochrome (black or white).
     * 
     * @param maxValue The maximum channel value.
     */
    virtual void monochrome(int maxValue) = 0;

    /**
     * @brief Convert the pixel to grayscale by averaging channel values.
     * 
     * @param maxValue The maximum channel value.
     */
    virtual void grayscale(int maxValue) = 0;

    /**
     * @brief Overloaded output operator for AbstractPixel.
     * 
     * @param os Output stream.
     * @param pixel Pointer to pixel to output.
     * @return Reference to the output stream.
     */
    inline friend std::ostream& operator<<(std::ostream& os, AbstractPixel* pixel) {
        pixel->print(os);
        return os;
    }
};