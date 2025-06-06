#pragma once 

#include "../TemplatePixel.hpp"

class RGBPixel8 : public TemplatePixel<uint8_t, 3> {
public:
    RGBPixel8(uint8_t red = 0, uint8_t green = 0, uint8_t blue = 0);
    virtual AbstractPixel* clone() const override;

    virtual void monochrome(int maxValue) override;
    virtual void grayscale(int maxValue) override;
private:
    enum Channels {
        RED,
        GREEN,
        BLUE
    };
};