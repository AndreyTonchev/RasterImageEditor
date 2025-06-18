#include "PGMImage.hpp"
#include "../../Pixels/PixelTypes/GrayPixel16.hpp"
#include "../../Pixels/PixelTypes/GrayPixel8.hpp"
#include "../PixelMatrix.hpp"



PGMImage::PGMImage() 
    : Image(), signature(PGMSignature::NONE), maxValue(-1), width(0), height(0) {
}

PGMImage::PGMImage(const std::string& filename) {
    std::ifstream file;
    try {

        if (filename == "") {
            throw FileException("Bad File Name.");
        }   
     
        file.open(filename, std::ios::in);
        if (!file) {
            throw FileException("Error opening file for reading.");
        }
    
        std::string imageSignature;
        file >> imageSignature;
        if (!file) {
            throw FileException("Error reading file data (Signature).");
        }
        
        file >> this->width >> this->height >> this->maxValue;
        if (!file) {
            throw FileException("Error reading file data (Dimensions)");
        }
    
        if (this->width == 0 || this->height == 0 || this->maxValue == 0) {
            throw FormatException("Bad Image values");
        }
    
    
        if (imageSignature == "P2") {
            this->signature = PGMSignature::P2;
            loadP2File(file);
        }
        else if (imageSignature == "P5") {
            this->signature = PGMSignature::P5;
            loadP5File(file);
        }
        else {
            throw FormatException("Signature not matching Image type.");
        }
        file.close();
    } catch (...) {
        file.close();
        throw;
    }
}

void PGMImage::print(std::ostream& os) const {
    std::string signatureStr = (signature == PGMSignature::P2) ? "P2" : "P5";

    os << signatureStr << std::endl;
    os << width << ' ' << height << std::endl;
    os << maxValue << std::endl;
    pixels->printR0(os);
    
}

void PGMImage::loadP2File(std::istream& is) {
    try {
        if (maxValue <= 255) {
            pixels = new PixelMatrix<GrayPixel8>(width, height, maxValue);
        }
        else if (maxValue <= 65535) {
            pixels = new PixelMatrix<GrayPixel16>(width, height, maxValue);
        }
        else {
            throw FormatException("Max pixel value is too large");
        }

        for (std::size_t y = 0; y < height; y++) {
            for (std::size_t x = 0; x < width; x++) {
                int pixelValue;

                if (!(is >> pixelValue)) {
                    throw FileException("Error reading pixels from file");
                }

                if (pixelValue < 0 || pixelValue > maxValue) {
                    throw FormatException("Bad pixel value at (" + std::to_string(x) + ',' + std::to_string(y) + ")");
                }
                pixels->at(x,y)->setChannel(GRAY, pixelValue);
            }
        }

    } catch (...) {
        delete pixels;
        throw;
    }
}

void PGMImage::loadP5File(std::istream& is) {
    
}
