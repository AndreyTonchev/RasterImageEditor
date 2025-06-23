#include "RGBPixel8.hpp"

RGBPixel8::RGBPixel8(uint8_t red, uint8_t green, uint8_t blue) 
    : TemplatePixel() {
    channels[RED] = red;
    channels[GREEN] = green;
    channels[BLUE] = blue;
}

AbstractPixel* RGBPixel8::clone() const {
    return new RGBPixel8(*this);
}

void RGBPixel8::monochrome(int maxValue) {
    double gray = 0.299 * channels[0] + 0.587 * channels[1] + 0.114 * channels[2];

    uint8_t value = (gray >= (maxValue / 2.0)) ? maxValue : 0;

    for (std::size_t i = 0; i < 3; i++) {
        channels[i] = value;
    }
}

void RGBPixel8::grayscale(int maxValue) {
    double gray = 0.299 * channels[0] + 0.587 * channels[1] + 0.114 * channels[2];

    for (std::size_t i = 0; i < 3; i++) {
        channels[i] = static_cast<uint8_t>(gray);
    }
}