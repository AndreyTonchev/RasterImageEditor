#pragma once 

#include "../TemplatePixel.hpp"

/**
 * @brief Represents an 8-bit RGB pixel with three color channels.
 * 
 * This class stores red, green, and blue channel values, each as an 8-bit unsigned integer.
 */
class RGBPixel8 : public TemplatePixel<uint8_t, 3> {
public:
    /**
     * @brief Constructs an 8-bit RGB pixel with optional initial channel values.
     * 
     * @param red Initial red channel value (default 0).
     * @param green Initial green channel value (default 0).
     * @param blue Initial blue channel value (default 0).
     */
    RGBPixel8(uint8_t red = 0, uint8_t green = 0, uint8_t blue = 0);

    /**
     * @brief Creates a deep copy of this pixel.
     * 
     * @return A pointer to the cloned RGBPixel8 object.
     */
    virtual AbstractPixel* clone() const override;

    /**
     * @brief Converts the pixel to a monochrome representation based on maxValue.
     * 
     * Overrides the base implementation for RGB pixels.
     * 
     * @param maxValue Maximum channel value for scaling.
     */
    virtual void monochrome(int maxValue) override;

    /**
     * @brief Converts the pixel to grayscale using its RGB channels.
     * 
     * Overrides the base implementation for RGB pixels.
     * 
     * @param maxValue Maximum channel value for scaling.
     */
    virtual void grayscale(int maxValue) override;

private:
    /**
     * @brief Enum representing the RGB channel indices.
     */
    enum Channels {
        RED,   ///< Red channel index.
        GREEN, ///< Green channel index.
        BLUE   ///< Blue channel index.
    };
};
