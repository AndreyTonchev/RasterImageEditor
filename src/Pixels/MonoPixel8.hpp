#pragma once

#include "TemplatePixel.hpp"

class MonoPixel8 : public TemplatePixel<uint8_t, 1> {
public:
    MonoPixel8(uint8_t value = 0);

    virtual AbstractPixel* clone() const override;
    virtual AbstractPixel* negative() const override;
    virtual AbstractPixel* grayscale() const override;

    enum Channels {
        MONO,
    };
};