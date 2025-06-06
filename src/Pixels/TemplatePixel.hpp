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
    virtual ~TemplatePixel() noexcept= default;

    virtual AbstractPixel* clone() const = 0;

    virtual void setChannel(std::size_t channel, uint32_t value) override;
    virtual uint32_t getChannel(std::size_t channel) const override;

    virtual void print(std::ostream& os = std::cout) const override;

public:
    virtual void negative(int maxValue) override;

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
void TemplatePixel<DataType, Channels>::setChannel(std::size_t channel, uint32_t value) {
    if (channel >= Channels) {
        throw std::out_of_range("Invalid Channel");
    }
    channels[channel] = (DataType)value;
}

template <typename DataType, std::size_t Channels>
uint32_t TemplatePixel<DataType, Channels>::getChannel(std::size_t channel) const {
    if (channel >= Channels) {
        throw std::out_of_range("Invalid Channel");
    }
    return channels[channel];
}

template <typename DataType, std::size_t Channels>
void TemplatePixel<DataType, Channels>::print(std::ostream& os) const {
    for (int i = 0; i < Channels; i++) {
        os << (int)channels[i] << " ";
    }
} 

template <typename DataType, std::size_t Channels>
void TemplatePixel<DataType, Channels>::negative(int maxValue) {
    for (int i = 0; i < Channels; i++) {
        channels[i] = maxValue - channels[i];
    }
}