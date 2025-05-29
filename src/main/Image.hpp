#pragma once

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "../Pixels/AbstractPixel.hpp"
#include "AbstractImage.hpp"
       

template <typename PixelType>
class Image : public AbstractImage {
public:
    virtual ~Image() noexcept = default;

    virtual void load() const = 0;
    virtual void save(const std::string& outputFilename = "") const = 0;
    virtual Image* clone() const = 0;

    std::size_t getWidth() const;
    std::size_t getHeigth() const;

    virtual void print(std::ostream& os = std::cout) const = 0;

    // void grayscale();
    // void monochrome();
    // void negative();
    // void rotateLeft();
    // void rotateRight();
    // void flipHorizontal();
    // void flipVertical();

protected:
    std::string filename;
    std::size_t width;
    std::size_t heigth;
    std::vector<std::vector<PixelType>> pixels;

protected:

    void resize(std::size_t new_width, std::size_t new_height);
};


