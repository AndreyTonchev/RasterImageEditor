#pragma once 

#include "../TemplatePixel.hpp"

/**
 * @brief Represents a 24-bit BGR pixel with three color channels.
 * 
 * This class stores red, green, and blue channel values, each as a 8-bit unsigned integer.
 */
class BGRPixel8 : public TemplatePixel<uint8_t, 3> {
public:
    /**
     * @brief Constructs a 8-bit BGR pixel with optional initial channel values.
     * 
     * @param blue Initial blue channel value (default 0).
     * @param green Initial green channel value (default 0).
     * @param red Initial red channel value (default 0).
     */
    BGRPixel8(uint8_t red = 0, uint8_t green = 0, uint8_t blue = 0);

    /**
     * @brief Creates a deep copy of this pixel.
     * 
     * @return A pointer to the cloned BGRPixel8 object.
     */
    virtual AbstractPixel* clone() const override;

    /**
     * @brief Converts the pixel to a monochrome representation based on maxValue.
     * 
     * Overrides the base implementation for BGR pixels.
     * 
     * @param maxValue Maximum channel value for scaling.
     */
    virtual void monochrome(int maxValue) override;

    /**
     * @brief Converts the pixel to grayscale using its BGR channels.
     * 
     * Overrides the base implementation for BGR pixels.
     * 
     * @param maxValue Maximum channel value for scaling.
     */
    virtual void grayscale(int maxValue) override;

private:
    /**
     * @brief Enum representing the BGR channel indices.
     */
    enum Channels {
        BLUE,   ///< Blue channel index.
        GREEN,  ///< Green channel index.
        RED     ///< Red channel index.
    };
};
