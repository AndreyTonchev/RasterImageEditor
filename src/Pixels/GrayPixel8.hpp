#pragma once

#include "TemplatePixel.hpp"

class GrayPixel8 : public TemplatePixel<uint8_t, 1> {
public:
    GrayPixel8(uint8_t value = 0);

    virtual AbstractPixel* clone() const override;
    virtual AbstractPixel* negative() const override;
    virtual AbstractPixel* grayscale() const override;

private:
    enum Channels {
        GRAY
    };
};