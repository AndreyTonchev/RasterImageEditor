#pragma once

#include <memory>
#include <string>
#include <vector>
#include <iostream>

#include "Pixel.hpp"

using Pixel8 = Pixel<uint8_t, 1>;           // 8-bit grayscale
using Pixel16 = Pixel<uint16_t, 1>;         // 16-bit grayscale
using PixelRGB8 = Pixel<uint8_t, 3>;        // 24-bit RGB
using PixelRGBA8 = Pixel<uint8_t, 4>;       // 32-bit RGBA
using PixelRGB16 = Pixel<uint16_t, 3>;      // 48-bit RGB
using PixelRGBA16 = Pixel<uint16_t, 4>;     // 64-bit RGBA
using PixelRGBf = Pixel<float, 3>;          // Floating-point RGB
using PixelRGBAf = Pixel<float, 4>;         // Floating-point RGBA

template <typename PixelType>
class Image {
public:

    Image(const std::string& filename, std::size_t width, std::size_t height);
    virtual ~Image() noexcept = default;

    virtual void load() const = 0;
    virtual void save(const std::string& OutputFilename = "") const = 0;
    virtual Image* clone() const = 0;

    std::size_t getWidth() const;
    std::size_t getHeigth() const;

    // void grayscale();
    // void monochrome();
    // void negative();
    // void rotateLeft();
    // void rotateRight();
    // void flipHorizontal();
    // void flipVertical();

protected:
    std::string filename;
    std::vector<std::vector<Pixel<PixelType>>> pixels;
    std::size_t width;
    std::size_t heigth;

protected:

    void resize(std::size_t new_width, std::size_t new_height);
    void initializePixels(std::size_t w, std::size_t h);
};



template <typename PixelType>
Image<PixelType>::Image(const std::string& filename, std::size_t width, std::size_t height) 
    : filename(filename), width(width), height(height) {
        initializePixels(width, height);
    }

template <typename PixelType>
std::size_t Image<PixelType>::getWidth() const {
    return width;
}    

template <typename PixelType>
std::size_t Image<PixelType>::getHeigth() const {
    return getHeigth;
}    

template <typename PixelType>
void Image<PixelType>::resize(std::size_t new_width, std::size_t new_height) {
    // TODO
}

template <typename PixelType>
void Image<PixelType>::initializePixels(std::size_t w, std::size_t h) {
    width = w;
    height = h;
    
    pixels = std::vector<std::vector<PixelType>>(height, std::vector<PixelType>(width));
}


