#pragma once

#include "TemplatePixel.hpp"

class GrayPixel16 : public TemplatePixel<uint16_t, 1> {
public:
    GrayPixel16(uint8_t value = 0);

    virtual AbstractPixel* clone() const override;
    virtual AbstractPixel* negative() const override;
    virtual AbstractPixel* grayscale() const override;
private:
    enum Channels {
        GRAY
    };
};