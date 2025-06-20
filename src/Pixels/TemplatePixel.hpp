#pragma once 

#include <iostream>
#include <memory>
#include <vector>

#include "../utils/Exceptions.hpp"
#include "AbstractPixel.hpp"

/**
 * @brief A templated pixel implementation supporting arbitrary data types and number of channels.
 * 
 * @tparam DataType The underlying data type for each channel (e.g., uint8_t, uint16_t).
 * @tparam Channels The number of channels (e.g., 1 for grayscale, 3 for RGB).
 */
template <typename DataType, std::size_t Channels>
class TemplatePixel : public AbstractPixel {
public:
    /**
     * @brief Constructs a pixel with all channels initialized to zero.
     */
    TemplatePixel();

    /**
     * @brief Virtual destructor.
     */
    virtual ~TemplatePixel() noexcept = default;

    /**
     * @brief Create a deep copy of this pixel.
     * 
     * @return A pointer to the newly cloned pixel.
     */
    virtual AbstractPixel* clone() const = 0;

    /**
     * @copydoc AbstractPixel::setChannel
     */
    virtual void setChannel(std::size_t channel, uint32_t value) override;

    /**
     * @copydoc AbstractPixel::getChannel
     */
    virtual uint32_t getChannel(std::size_t channel) const override;

    /**
     * @copydoc AbstractPixel::print
     */
    virtual void print(std::ostream& os = std::cout) const override;

    /**
     * @copydoc AbstractPixel::copyFrom
     */
    virtual void copyFrom(const AbstractPixel* other) override;

    /**
     * @copydoc AbstractPixel::negative
     */
    virtual void negative(int maxValue) override;

    /**
     * @copydoc AbstractPixel::monochrome
     */
    virtual void monochrome(int maxValue) override;

    /**
     * @copydoc AbstractPixel::grayscale
     */
    virtual void grayscale(int maxValue) override;

protected:
    /**
     * @brief The channel values of the pixel.
     */
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

template <typename DataType, std::size_t Channels>
void TemplatePixel<DataType, Channels>::monochrome(int maxValue) {
    long sum = 0;
    int threshold = (maxValue * Channels) / 2;

    for (int i = 0; i < Channels; i++) {
        sum += channels[i];
    }

    if (sum >= threshold) {
        for (int i = 0; i < Channels; i++) {
            channels[i] = maxValue;
        }   
    }
    else {
        for (int i = 0; i < Channels; i++) {
            channels[i] = 0;
        } 
    }
}

template <typename DataType, std::size_t Channels>
void TemplatePixel<DataType, Channels>::grayscale(int maxValue) {
    long sum = 0;

    for (int i = 0; i < Channels; i++) {
        sum += channels[i];
    }

    DataType gray = static_cast<DataType>(sum / Channels);

    for (int i = 0; i < Channels; i++) {
        channels[i] = gray;
    }   
}

template <typename DataType, std::size_t Channels>
void TemplatePixel<DataType, Channels>::copyFrom(const AbstractPixel* other) {
    const TemplatePixel<DataType, Channels>* casted =
        dynamic_cast<const TemplatePixel<DataType, Channels>*>(other);

    if (!casted) {
        throw FormatException("Pixel type mismatch in copyFrom");
    }

    for (std::size_t i = 0; i < Channels; ++i) {
        this->channels[i] = casted->channels[i];
    }
}