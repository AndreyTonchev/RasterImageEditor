#pragma once

class AbstractPixel {
public:
    virtual ~AbstractPixel() = default;

    virtual AbstractPixel* clone() const = 0;
    virtual AbstractPixel* negative() const = 0;
    virtual AbstractPixel* grayscale() const = 0;

private:
};