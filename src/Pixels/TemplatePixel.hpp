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
    std::vector<DataType> channels;
};

template <typename DataType, std::size_t Channels>
TemplatePixel<DataType, Channels>::TemplatePixel()  
    : channels(Channels) {
}

template <typename DataType, std::size_t Channels>
const DataType& TemplatePixel<DataType, Channels>::operator[](std::size_t channel) const {
    return channels[channel];
}