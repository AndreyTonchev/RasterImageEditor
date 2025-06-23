#include "BGRPixel8.hpp"

BGRPixel8::BGRPixel8(uint8_t blue, uint8_t green, uint8_t red) 
    : TemplatePixel() {
    channels[BLUE] = blue;
    channels[GREEN] = green;
    channels[RED] = red;
}

AbstractPixel* BGRPixel8::clone() const {
    return new BGRPixel8(*this);
}

void BGRPixel8::monochrome(int maxValue) {
    double gray = 0.114 * channels[0] + 0.587 * channels[1] + 0.299 * channels[2];

    uint8_t value = (gray >= (maxValue / 2.0)) ? maxValue : 0;

    for (std::size_t i = 0; i < 3; i++) {
        channels[i] = value;
    }
}

void BGRPixel8::grayscale(int maxValue) {
    double gray = 0.114 * channels[0] + 0.587 * channels[1] + 0.299 * channels[2];

    for (std::size_t i = 0; i < 3; i++) {
        channels[i] = static_cast<uint8_t>(gray);
    }
}