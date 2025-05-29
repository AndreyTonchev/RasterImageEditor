#pragma once 

#include <iostream>
#include <memory>

#include "../utils/Exceptions.hpp"


class Pixel {
public:
    virtual ~Pixel() = default;

    virtual Pixel* clone() const = 0;
    virtual Pixel* negative() const = 0;
    virtual Pixel* grayscale() const = 0;

    inline virtual int getValue() const { return 0; }
    inline virtual int getR() const { return 0; }
    inline virtual int getG() const { return 0; }
    inline virtual int getB() const { return 0; }

    inline virtual void setValue(int) { return; };
    inline virtual void setRGB(int, int, int) { return; }
};