#pragma once

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "../Pixels/AbstractPixel.hpp"
#include "AbstractPixelMatrix.hpp"
#include "../utils/Exceptions.hpp"
       
enum class Orientation {
    NONE = -1,
    R0,     // Rotate 0
    R90,    // Rotate 90
    R180,   // Rotate 180
    R270,   // Rotate 270
    MH,     // Mirror Horizontal
    MV,     // Mirror Vertical
    DF,     // Diagonal Flip
    AD,     // Anti Diagonal Flip
};

class Image {
public:
    Image();
    Image(const Image& other);
    Image& operator=(const Image& other);
    virtual ~Image() noexcept { delete pixels; };
    
    virtual Image* clone() const = 0;

    std::size_t getWidth() const;
    std::size_t getHeight() const;
    std::string getFilename() const;
    
    virtual void print(std::ostream& os = std::cout) const = 0;

    
    public:
    void negative();
    void grayscale();
    void monochrome();
    void save(const std::string& filename) const;
    
protected:
    std::string filename;
    AbstractPixelMatrix* pixels;
    Orientation orientation;

    static Orientation orientationTable[8][8];
};
