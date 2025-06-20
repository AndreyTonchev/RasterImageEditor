#pragma once

#include "../TemplatePixel.hpp"

/**
 * @brief Represents an 8-bit monochrome pixel with a single channel.
 * 
 * This class is intended for black-and-white images where each pixel is either on or off.
 */
class MonoPixel8 : public TemplatePixel<uint8_t, 1> {
public:
    /**
     * @brief Constructs an 8-bit monochrome pixel with an optional initial value.
     * 
     * @param value The initial monochrome value (default is 0).
     */
    MonoPixel8(uint8_t value = 0);

    /**
     * @brief Creates a deep copy of this pixel.
     * 
     * @return A pointer to the cloned pixel object.
     */
    virtual AbstractPixel* clone() const override;

    /**
     * @brief Enum to represent the monochrome channel index.
     */
    enum Channels {
        MONO  ///< Index for the monochrome channel.
    };
};
