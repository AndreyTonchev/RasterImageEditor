#include "GrayPixel8.hpp"

GrayPixel8::GrayPixel8(uint8_t value) 
    : value(value) {
}

Pixel* GrayPixel8::clone() const  {
    return new GrayPixel8(*this);
}

Pixel* GrayPixel8::negative() const  {
    return new GrayPixel8(*this); // TODO
}

Pixel* GrayPixel8::grayscale() const  {
    return new GrayPixel8(*this);
}

int GrayPixel8::getValue() const  {
    return value;
}

void GrayPixel8::setValue(int newValue)  {
    this->value = value;
}
