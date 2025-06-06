#include "GrayPixel16.hpp"

GrayPixel16::GrayPixel16(uint8_t value) 
    : TemplatePixel() {
    channels[GRAY] = 0;
}

AbstractPixel* GrayPixel16::clone() const  {
    return new GrayPixel16(*this);
}

