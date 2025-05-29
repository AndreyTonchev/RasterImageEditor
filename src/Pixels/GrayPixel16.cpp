#include "GrayPixel16.hpp"

GrayPixel16::GrayPixel16(uint8_t value) 
    : value(value) {
}

Pixel* GrayPixel16::clone() const  {
    return new GrayPixel16(*this);
}

Pixel* GrayPixel16::negative() const  {
    return new GrayPixel16(*this);
}

Pixel* GrayPixel16::grayscale() const  {
    return new GrayPixel16(*this);
}

int GrayPixel16::getValue() const  {
    return value;
}

void GrayPixel16::setValue(int newValue)  {
    this->value = value;
}
