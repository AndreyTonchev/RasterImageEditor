#pragma once

#include <iostream>
#include <vector>

#include "../Pixels/AbstractPixel.hpp"

class AbstractPixelMatrix {
public:
    virtual ~AbstractPixelMatrix() noexcept = default;

    virtual std::size_t getWidth() const = 0;
    virtual std::size_t getHeight() const = 0;

    virtual AbstractPixel* at(std::size_t w, std::size_t h) = 0;
    virtual const AbstractPixel* at(std::size_t w, std::size_t h) const = 0;

    virtual AbstractPixelMatrix* clone() const = 0;

public:
    virtual void printR0(std::ostream& os = std::cout) const = 0;
    virtual void printR90(std::ostream& os = std::cout) const = 0;
    virtual void printR180(std::ostream& os = std::cout) const = 0;
    virtual void printR270(std::ostream& os = std::cout) const = 0;
    virtual void printMH(std::ostream& os = std::cout) const = 0;
    virtual void printMV(std::ostream& os = std::cout) const = 0;
    virtual void printDF(std::ostream& os = std::cout) const = 0;
    virtual void printAD(std::ostream& os = std::cout) const = 0;

public: 
    virtual void negative() = 0;
    virtual void grayscale() = 0;
    virtual void monochrome() = 0;

};