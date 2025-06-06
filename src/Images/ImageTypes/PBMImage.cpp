#include "PBMImage.hpp"
#include "../../Pixels/PixelTypes/MonoPixel8.hpp"
#include "../PixelMatrix.hpp"


PBMImage::PBMImage() 
    : Image(), signature(PBMSignature::NONE), width(0), height(0) {
}

PBMImage::PBMImage(const std::string& filename) {
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
        
        file >> this->width >> this->height;
        if (!file) {
            throw FileException("Error reading file data (Dimensions)");
        }

        if (this->width == 0 || this->height == 0 ) {
            throw FormatException("Bad Image values");
        }


        if (imageSignature == "P1") {
            this->signature = PBMSignature::P4;
            loadP1File(file);
        }
        else if (imageSignature == "P4") {
            this->signature = PBMSignature::P4;
            loadP4File(file);
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

void PBMImage::print(std::ostream& os) const {
    std::string signatureStr = (signature == PBMSignature::P1) ? "P1" : "P4";

    os << signatureStr << std::endl;
    os << width << height << std::endl;
    os << pixels << std::endl;
    
}

void PBMImage::loadP1File(std::istream& is) {
    try {
        pixels = new PixelMatrix<MonoPixel8>(width, height, 1);
        
        for (std::size_t y = 0; y < height; y++) {
            for (std::size_t x = 0; x < width; x++) {
                int pixelValue;

                if (!(is >> pixelValue)) {
                    throw FileException("Error reading pixels from file");
                }

                if (pixelValue < 0 || pixelValue > 1) {
                    throw FormatException("Bad pixel value at (" + std::to_string(x) + ',' + std::to_string(y) + ")");
                }
                pixels->at(x,y)->setChannel(MonoPixel8::Channels::MONO, pixelValue);
            }
        }

    } catch (...) {
        delete pixels;
        throw;
    }
}

void PBMImage::loadP4File(std::istream& is) {

}