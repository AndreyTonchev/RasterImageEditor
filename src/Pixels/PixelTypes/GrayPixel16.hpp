#pragma once

#include "../TemplatePixel.hpp"

/**
 * @brief Represents a 16-bit grayscale pixel with a single channel.
 * 
 * This class extends TemplatePixel with a uint16_t data type and one channel,
 * suitable for high dynamic range grayscale images.
 */
class GrayPixel16 : public TemplatePixel<uint16_t, 1> {
public:
    /**
     * @brief Constructs a 16-bit grayscale pixel with an optional initial value.
     * 
     * @param value The grayscale value to initialize the pixel with (default is 0).
     */
    GrayPixel16(uint8_t value = 0);

    /**
     * @brief Creates a deep copy of this pixel.
     * 
     * @return A pointer to the cloned pixel object.
     */
    virtual AbstractPixel* clone() const override;

private:
    /**
     * @brief Enum to represent the grayscale channel index.
     */
    enum Channels {
        GRAY  ///< Index for the grayscale channel.
    };
};
