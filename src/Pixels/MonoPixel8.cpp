#include "MonoPixel8.hpp"

MonoPixel8::MonoPixel8(uint8_t value)
    : TemplatePixel() {
        channels[MONO] = value;
}

AbstractPixel* MonoPixel8::clone() const  {
    return new MonoPixel8(*this);
}

