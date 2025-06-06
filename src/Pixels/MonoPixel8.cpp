#include "MonoPixel8.hpp"

MonoPixel8::MonoPixel8(uint8_t value)
    : TemplatePixel() {
        channels[MONO] = value;
}

AbstractPixel* MonoPixel8::clone() const  {
    return new MonoPixel8(*this);
}

AbstractPixel* MonoPixel8::negative() const  {
    return new MonoPixel8(*this); // TODO
}

AbstractPixel* MonoPixel8::grayscale() const  {
    return new MonoPixel8(*this);
}


