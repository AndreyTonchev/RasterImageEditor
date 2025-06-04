#pragma once

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "../Pixels/AbstractPixel.hpp"
#include "AbstractImage.hpp"
#include "AbstractPixelMatrix.hpp"
       

// template <typename PixelType>
// class Image : public AbstractImage {
// public:
//     Image();
//     virtual ~Image() noexcept = default;

//     virtual Image* clone() const = 0;

//     std::size_t getWidth() const;
//     std::size_t getHeigth() const;

//     virtual void print(std::ostream& os = std::cout) const = 0;

//     // void grayscale();
//     // void monochrome();
//     // void negative();
//     // void rotateLeft();
//     // void rotateRight();
//     // void flipHorizontal();
//     // void flipVertical();

// protected:
//     std::string filename;
//     std::size_t width;
//     std::size_t heigth;
    


// protected:

//     void resize(std::size_t new_width, std::size_t new_height);
// };

class Image {
public:
    Image();

    virtual ~Image() noexcept { delete pixels; };
    virtual Image* clone() const = 0;
    virtual void grayscale();
    virtual void negative();

    std::size_t getWidth() const;
    std::size_t getHeight() const;
    
    virtual void print(std::ostream& os = std::cout) const = 0;

protected:
    std::string filename;

    AbstractPixelMatrix* pixels;

};
