#pragma once

#include <iostream>
#include <vector>

#include "Image.hpp"
#include "../Pixels/TemplatePixel.hpp"
#include "../utils/Exceptions.hpp"


template <typename PixelType>
class PixelMatrix : public AbstractPixelMatrix {
public:
    PixelMatrix(std::size_t width, std::size_t height, std::size_t maxValue);

    virtual std::size_t getWidth() const override;
    virtual std::size_t getHeight() const override;
    
    virtual AbstractPixel* at(std::size_t w, std::size_t h) override;
    virtual const AbstractPixel* at(std::size_t w, std::size_t h) const override;

    virtual AbstractPixelMatrix* clone() const override;

public:
    virtual void printR0(std::ostream& os = std::cout) const override;
    virtual void printR90(std::ostream& os = std::cout) const override;
    virtual void printR180(std::ostream& os = std::cout) const override;
    virtual void printR270(std::ostream& os = std::cout) const override;
    virtual void printMH(std::ostream& os = std::cout) const override;
    virtual void printMV(std::ostream& os = std::cout) const override;
    virtual void printDF(std::ostream& os = std::cout) const override;
    virtual void printAD(std::ostream& os = std::cout) const override;

public:
    virtual void negative() override;
    virtual void grayscale() override;
    virtual void monochrome() override;

private:
    int width;
    int height;
    int maxValue;
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
AbstractPixelMatrix* PixelMatrix<PixelType>::clone() const {
    return new PixelMatrix<PixelType>(*this);
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

template <typename PixelType>
void PixelMatrix<PixelType>::printR0(std::ostream& os) const {
    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            pixels[h][w].print(os);
        }
        os << std::endl;
    } 
}

template <typename PixelType>
void PixelMatrix<PixelType>::printR90(std::ostream& os) const {
    for (int w = 0; w < width; w++) {
        for (int h = height - 1; h >= 0; h--) {
            pixels[h][w].print(os);
        }
        os << std::endl;
    }
}

template <typename PixelType>
void PixelMatrix<PixelType>::printR180(std::ostream& os) const {
    for (int w = 0; w < width; w++) {
        for (int h = height - 1; h >= 0; h--) {
            pixels[h][w].print(os);
        }
        os << std::endl;
    }
}

template <typename PixelType>
void PixelMatrix<PixelType>::printR270(std::ostream& os) const {
    for (int w = width - 1; w >= 0; w--) {
        for (int h = 0; h < height; h++) {
            pixels[h][w].print(os);
        }
        os << std::endl;
    }
}

template <typename PixelType>
void PixelMatrix<PixelType>::printMH(std::ostream& os) const {
    for (int h = 0; h < height; h++) {
        for (int w = width - 1; w >= 0; w--) {
            pixels[h][w].print(os);
        }
        os << std::endl;
    }
}

template <typename PixelType>
void PixelMatrix<PixelType>::printMV(std::ostream& os) const {
    for (int h = height - 1; h >= 0; h--) {
        for (int w = 0; w < width; w++) {
            pixels[h][w].print(os);
        }
        os << std::endl;
    }
}

template <typename PixelType>
void PixelMatrix<PixelType>::printDF(std::ostream& os) const {
    for (int w = 0; w < width; w++) {
        for (int h = 0; h < height; h++) {
            pixels[h][w].print(os);
        }
        os << std::endl;
    }
}

template <typename PixelType>
void PixelMatrix<PixelType>::printAD(std::ostream& os) const {
    for (int w = width - 1; w >= 0; w--) {
        for (int h = height - 1; h >= 0; h--) {
            pixels[h][w].print(os);
        }
        os << std::endl;
    }
}
