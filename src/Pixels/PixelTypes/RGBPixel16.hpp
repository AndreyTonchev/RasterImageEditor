#pragma once 

#include "../TemplatePixel.hpp"

/**
 * @brief Represents a 16-bit RGB pixel with three color channels.
 * 
 * This class stores red, green, and blue channel values, each as a 16-bit unsigned integer.
 */
class RGBPixel16 : public TemplatePixel<uint16_t, 3> {
public:
    /**
     * @brief Constructs a 16-bit RGB pixel with optional initial channel values.
     * 
     * @param red Initial red channel value (default 0).
     * @param green Initial green channel value (default 0).
     * @param blue Initial blue channel value (default 0).
     */
    RGBPixel16(uint16_t red = 0, uint16_t green = 0, uint16_t blue = 0);

    /**
     * @brief Creates a deep copy of this pixel.
     * 
     * @return A pointer to the cloned RGBPixel16 object.
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
