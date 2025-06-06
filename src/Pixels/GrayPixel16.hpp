#pragma once

#include "TemplatePixel.hpp"

class GrayPixel16 : public TemplatePixel<uint16_t, 1> {
public:
    GrayPixel16(uint8_t value = 0);

    virtual AbstractPixel* clone() const override;
private:
    enum Channels {
        GRAY
    };
};