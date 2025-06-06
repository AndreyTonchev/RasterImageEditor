#pragma once

#include <iostream>
#include <vector>

#include "../Pixels/TemplatePixel.hpp"
#include "../utils/Exceptions.hpp"

template <typename PixelType>
class PixelMatrix : public AbstractPixelMatrix {
public:
    PixelMatrix(std::size_t width, std::size_t height, std::size_t maxValue);

    std::size_t getWidth() const override;
    std::size_t getHeight() const override;
    
    AbstractPixel* at(std::size_t w, std::size_t h) override;
    const AbstractPixel* at(std::size_t w, std::size_t h) const override;

    void print(std::ostream& os = std::cout) const override;

public:
    virtual void negative() override;
    virtual void grayscale() override;
    virtual void monochrome() override;

public:
    std::size_t width;
    std::size_t height;
    std::size_t maxValue;
    std::vector<std::vector<PixelType>> pixels;
};

template <typename PixelType>
PixelMatrix<PixelType>::PixelMatrix(std::size_t width, std::size_t height, std::size_t maxValue)
    : width(width), height(height), maxValue(maxValue), pixels(height, std::vector<PixelType>(width)) {
}

template <typename PixelType>
std::size_t PixelMatrix<PixelType>::getHeight() const {
    return height;
}

template <typename PixelType>
std::size_t PixelMatrix<PixelType>::getWidth() const {
    return width;
}

template <typename PixelType>
const AbstractPixel* PixelMatrix<PixelType>::at(std::size_t w, std::size_t h) const {
    if (h >= height || w >= width) {
        throw FormatException("PixelMatrix::at() index out of range");
    }
    return &pixels[h][w];
}
    
template <typename PixelType>
AbstractPixel* PixelMatrix<PixelType>::at(std::size_t w, std::size_t h) {
    if (h >= height || w >= width) {
        throw FormatException("PixelMatrix::at() index out of range");
    }
    return &pixels[h][w];
}

template <typename PixelType>
void PixelMatrix<PixelType>::print(std::ostream& os) const {
    for (std::size_t y = 0; y < height; y++) {
        for (std::size_t x = 0; x < width; x++) {
            pixels[y][x].print(os);
        }
        os << std::endl;
    }
}

template <typename PixelType>
void PixelMatrix<PixelType>::negative() {
    for (std::size_t y = 0; y < height; y++) {
        for (std::size_t x = 0; x < width; x++) {
            pixels[y][x].negative(maxValue);
        }
    }
}

template <typename PixelType>
void PixelMatrix<PixelType>::monochrome() {
    for (std::size_t y = 0; y < height; y++) {
        for (std::size_t x = 0; x < width; x++) {
            pixels[y][x].monochrome(maxValue);
        }
    }
}

template <typename PixelType>
void PixelMatrix<PixelType>::grayscale() {
    for (std::size_t y = 0; y < height; y++) {
        for (std::size_t x = 0; x < width; x++) {
            pixels[y][x].grayscale(maxValue);
        }
    }
}
