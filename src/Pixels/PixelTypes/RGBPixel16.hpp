#pragma once 

#include "../TemplatePixel.hpp"

class RGBPixel16 : public TemplatePixel<uint16_t, 3> {
public:
    RGBPixel16(uint16_t red = 0, uint16_t green = 0, uint16_t blue = 0);
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