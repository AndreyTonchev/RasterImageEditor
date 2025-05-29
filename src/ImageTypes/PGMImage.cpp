#include "PGMImage.hpp"
#include "../Pixels/GrayPixel16.hpp"
#include "../Pixels/GrayPixel8.hpp"



PGMImage::PGMImage() 
    :   signature(Signature::None), maxValue(-1) {
}

PGMImage::PGMImage(const std::string& filename) {
    if (filename == "") {
        throw FileException("Bad File Name.");
    }

    std::ifstream file(filename, std::ios::in);
    if (!file) {
        throw FileException("Error opening file for reading.");
    }

    file >> this->width >> this->heigth >> this->maxValue;
    if (!file) {
        throw FileException("Error reading file data");
    }

    if (this->width == 0 || this->heigth == 0 || this->maxValue == 0) {
        throw FormatException("Bad Image values");
    }

    std::string imageSignature;
    file >> imageSignature;
    if (!file) {
        throw FileException("Error reading file data.");
    }

    if (imageSignature == "P2") {
        this->signature = Signature::P2;
        loadP2File(file);
    }
    else if (imageSignature == "P5") {
        this->signature = Signature::P5;
        loadP5File(file);
    }
    else {
        throw FormatException("Signature not matching Image type.");
    }
}

// PGMImage::PGMImage(const Image& other) {

// }

// PGMImage& PGMImage::operator=(const Image& other) {

// }

// PGMImage::~PGMImage() {

// }


void PGMImage::load() const  {

}

void PGMImage::save(const std::string& outputFilename) const  {

}

void PGMImage::print(std::ostream& os) const {

}

void PGMImage::loadP2File(std::ifstream& is) {
    try {
        if (maxValue <= 255) {
            
        }
        if (maxValue <= 65535) {
            
        }
        else {
            throw FormatException("Max pixlel value is too latge");
        }

        for (std::size_t y = 0; y < heigth; y++) {
            for (std::size_t x = 0; x < width; x++) {
                int pixelValue;

                if (!(is >> pixelValue)) {
                    throw FileException("Error reading pixels from file");
                }

                if (pixelValue < 0 || pixelValue > maxValue) {
                    throw FormatException("Bad pixel value at (" + std::to_string(x) + ',' + std::to_string(y) + ")");
                }
                
            }
        }

    } catch (...) {
        throw;
    }
}

void PGMImage::loadP2File(std::ifstream& is) {
    
}
