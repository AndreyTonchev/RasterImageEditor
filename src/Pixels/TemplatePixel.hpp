#pragma once 

#include <iostream>
#include <memory>
#include <vector>

#include "../utils/Exceptions.hpp"
#include "AbstractPixel.hpp"


template <typename DataType, std::size_t Channels>
class TemplatePixel : public AbstractPixel {
public:
    TemplatePixel();
    virtual ~Pixel() = default;

    virtual AbstractPixel* clone() const = 0;
    virtual AbstractPixel* negative() const = 0;
    virtual AbstractPixel* grayscale() const = 0;

    const DataType& operator[](std::size_t channel) const;

protected:
    DataType channels[Channels];
};

template <typename DataType, std::size_t Channels>
TemplatePixel<DataType, Channels>::TemplatePixel() {
    for (std::size_t i = 0; i < Channels; i++) {
        channels[i] = 0;
    }
}

template <typename DataType, std::size_t Channels>
const DataType& TemplatePixel<DataType, Channels>::operator[](std::size_t channel) const {
    return channels[channel];
}
