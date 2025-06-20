#pragma once

#include "../TemplatePixel.hpp"

/**
 * @brief Represents an 8-bit grayscale pixel with a single channel.
 * 
 * This class inherits from TemplatePixel with uint8_t data type and one channel.
 */
class GrayPixel8 : public TemplatePixel<uint8_t, 1> {
public:
    /**
     * @brief Constructs a grayscale pixel with an optional initial value.
     * 
     * @param value The grayscale value to initialize the pixel with (default is 0).
     */
    GrayPixel8(uint8_t value = 0);

    /**
     * @brief Creates a deep copy of this pixel.
     * 
     * @return A pointer to the newly cloned pixel.
     */
    virtual AbstractPixel* clone() const override;

private:
    /**
     * @brief Enum to represent channel indices.
     */
    enum Channels {
        GRAY  ///< Index for the single grayscale channel.
    };
};
