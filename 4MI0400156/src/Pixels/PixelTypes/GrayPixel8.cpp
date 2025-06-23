#include "GrayPixel8.hpp"

GrayPixel8::GrayPixel8(uint8_t value) 
    : TemplatePixel() {
    channels[GRAY] = value;
}

AbstractPixel* GrayPixel8::clone() const  {
    return new GrayPixel8(*this);
}

