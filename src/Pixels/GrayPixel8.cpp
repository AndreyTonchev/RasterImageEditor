#include "GrayPixel8.hpp"

GrayPixel8::GrayPixel8(uint8_t value) 
    : TemplatePixel() {
    channels[GRAY] = 0;
}

AbstractPixel* GrayPixel8::clone() const  {
    return new GrayPixel8(*this);
}

AbstractPixel* GrayPixel8::negative() const  {
    return new GrayPixel8(*this); // TODO
}

AbstractPixel* GrayPixel8::grayscale() const  {
    return new GrayPixel8(*this);
}

