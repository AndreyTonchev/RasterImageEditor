#include "PPMImage.hpp"
#include "../../Pixels/PixelTypes/RGBPixel8.hpp"
#include "../../Pixels/PixelTypes/RGBPixel16.hpp"
#include "../PixelMatrix.hpp"

PPMImage::PPMImage() 
    : Image(), signature(PPMSignature::NONE), maxValue(-1), width(0), height(0) {
}

PPMImage::PPMImage(const std::string& filename) 
     {

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

        if (imageSignature == "P3") {
            this->signature = PPMSignature::P3;
            loadP3File(file);
        }
        else if (imageSignature == "P6") {
            this->signature = PPMSignature::P6;
            loadP6File(file);
        }
        else {
            std::cout << "DSAadsads";
            throw FormatException("Signature not matching Image type.");
        }

        file.close();

    } catch (...) {
        file.close();
        throw;
    }
}

void PPMImage::print(std::ostream& os) const {
    std::string signatureStr = (signature == PPMSignature::P3) ? "P3" : "P6";

    os << signatureStr << std::endl;
    os << width << ' ' << height << std::endl;
    os << maxValue << std::endl;
    os << pixels << std::endl;
    
}

void PPMImage::loadP3File(std::istream& is) {

    try {
        if (maxValue <= 255) {
            pixels = new PixelMatrix<RGBPixel8>(width, height, maxValue);
        }
        else if (maxValue <= 65535) {
            pixels = new PixelMatrix<RGBPixel16>(width, height, maxValue);
        }
        else {
            throw FormatException("Max pixel value is too large");
        }

        for (std::size_t y = 0; y < height; y++) {
            for (std::size_t x = 0; x < width; x++) {
                int red, green, blue;

                if (!(is >> red >> green >> blue)) {
                    throw FileException("Error reading pixels from file");
                }

                if (red < 0 || green < 0 || blue < 0 ||
                    red > maxValue || green > maxValue || blue > maxValue) {
                    throw FormatException("Bad pixel value at (" + std::to_string(x) + ',' + std::to_string(y) + ")");
                }
                pixels->at(x,y)->setChannel(RED, red);
                pixels->at(x,y)->setChannel(GREEN, green);
                pixels->at(x,y)->setChannel(BLUE, blue);
            }
        }

    } catch (...) {
        delete pixels;
        throw;
    }
}

void PPMImage::loadP6File(std::istream& is) {
    
}
