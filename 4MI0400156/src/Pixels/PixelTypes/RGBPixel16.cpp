#include "RGBPixel16.hpp"

RGBPixel16::RGBPixel16(uint16_t red, uint16_t green, uint16_t blue) 
    : TemplatePixel() {
    channels[RED] = red;
    channels[GREEN] = green;
    channels[BLUE] = blue;
}

AbstractPixel* RGBPixel16::clone() const {
    return new RGBPixel16(*this);
}

void RGBPixel16::monochrome(int maxValue) {
    double gray = 0.299 * channels[0] + 0.587 * channels[1] + 0.114 * channels[2];

    uint16_t value = (gray >= (maxValue / 2.0)) ? maxValue : 0;

    for (std::size_t i = 0; i < 3; i++) {
        channels[i] = value;
    }
}

void RGBPixel16::grayscale(int maxValue) {
    double gray = 0.299 * channels[0] + 0.587 * channels[1] + 0.114 * channels[2];

    for (std::size_t i = 0; i < 3; i++) {
        channels[i] = static_cast<uint16_t>(gray);
    }
}