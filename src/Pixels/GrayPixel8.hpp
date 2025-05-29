#pragma once

#include "../main/Pixel.hpp"

class GrayPixel8 : public Pixel {
public:
    GrayPixel8(uint8_t value = 0);

    Pixel* clone() const override;
    Pixel* negative() const override;
    Pixel* grayscale() const override;

    int getValue() const override;
    void setValue(int newValue) override;

private:
    uint8_t value;
};