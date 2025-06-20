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
    std::size_t getMaxValue() const;
    std::string getFilename() const;
    
    virtual AbstractPixel* at(std::size_t w, std::size_t h);
    virtual const AbstractPixel* at(std::size_t w, std::size_t h) const ;
    bool resize(std::size_t newWidth, std::size_t newHeight);

    virtual void print(std::ostream& os = std::cout) const = 0;
    void printPixels(std::ostream& os = std::cout) const;
    void printDimensions(std::ostream& os = std::cout) const;


    void transformOrientation(Orientation apply);
    
    public:
    void negative();
    void grayscale();
    void monochrome();
    void save(const std::string& filename) const;
    
protected:  
    std::string filename;

    int height;
    int width;
    int maxValue;

    Orientation orientation;
    AbstractPixelMatrix* pixels;

    static Orientation orientationTable[8][8];
};
