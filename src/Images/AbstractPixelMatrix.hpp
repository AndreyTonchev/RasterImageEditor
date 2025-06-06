#pragma once

#include <iostream>
#include <vector>

#include "../Pixels/AbstractPixel.hpp"

class AbstractPixelMatrix {
public:
    virtual ~AbstractPixelMatrix() noexcept = default;

    virtual std::size_t getWidth() const = 0;
    virtual std::size_t getHeight() const = 0;
    virtual void print(std::ostream& os = std::cout) const = 0;

    virtual AbstractPixel* at(std::size_t w, std::size_t h) = 0;
    virtual const AbstractPixel* at(std::size_t w, std::size_t h) const = 0;

    friend std::ostream& operator<<(std::ostream& os, AbstractPixelMatrix* pixelMatrix) {
        pixelMatrix->print(os);
        return os;
    }

public: 
    // void grayscale();
    // void monochrome();
    virtual void negative() = 0;
    virtual void grayscale() = 0;
    virtual void monochrome() = 0;

    
};