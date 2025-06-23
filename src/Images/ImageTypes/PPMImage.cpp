#include "PPMImage.hpp"
#include "../../Pixels/PixelTypes/RGBPixel8.hpp"
#include "../../Pixels/PixelTypes/RGBPixel16.hpp"
#include "../ImageFactory/ImageRegistrar.hpp"
#include "../PixelMatrix.hpp"

PPMImage::PPMImage() 
    : Image(), signature(PPMSignature::NONE) {
}

PPMImage::PPMImage(const std::string& filename) {
    this->filename = filename;
    std::ifstream file;
    try {
        if (filename == "") {
            throw FileException("Bad File Name.");
        }   
    
        file.open(filename, std::ios::in);
        if (!file) {
            throw FileException("Error opening file for reading.");
        }

        skipComments(file);

        std::string imageSignature;
        file >> imageSignature;
        if (!file) {
            throw FileException("Error reading file data (Signature).");
        }
        
        skipComments(file);

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
            throw FormatException("Signature not matching Image type.");
        }

        file.close();

    } catch (...) {
        file.close();
        throw;
    }
}

void PPMImage::save(const std::string& filename) {
    if (filename == "") {
        throw FileException("Bad File Name.");
    }   
    
    std::ofstream file;
    if (signature == PPMSignature::P3) {
        file.open(filename);
        if (!file) {
            throw FileException("Failed to open file for writing: " + filename);
        }

        file << "P3\n";
        printDimensions(file);
        file  << maxValue << "\n";
        printPixelsBinary(file);
    } 
    else if (signature == PPMSignature::P6) {   
        file.open(filename, std::ios::binary);
        if (!file) {
            throw FileException("Failed to open file for writing: " + filename);
        }

        file << "P6\n";
        printDimensions(file);
        file  << maxValue << "\n";
        printPixelsBinary(file);
    }

    file.close();
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

        skipComments(is);
        
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
    try {
        if (maxValue <= 255) {
            pixels = new PixelMatrix<RGBPixel8>(width, height, maxValue);

            for (std::size_t y = 0; y < height; y++) {
                for (std::size_t x = 0; x < width; x++) {
                    unsigned char rgb[3];
                    if (!is.read(reinterpret_cast<char*>(rgb), 3)) {
                        throw FileException("Failed to read RGB data.");
                    }

                    pixels->at(x, y)->setChannel(RED, rgb[0]);
                    pixels->at(x, y)->setChannel(GREEN, rgb[1]);
                    pixels->at(x, y)->setChannel(BLUE, rgb[2]);
                }
            }
        }
        else if (maxValue <= 65535) {
            pixels = new PixelMatrix<RGBPixel16>(width, height, maxValue);

            for (std::size_t y = 0; y < height; ++y) {
                for (std::size_t x = 0; x < width; ++x) {
                    unsigned char rgb[6];
                    if (!is.read(reinterpret_cast<char*>(rgb), 6)) {
                        throw FileException("Failed to read 16-bit RGB data.");
                    }

                    int red   = (rgb[0] << 8) | rgb[1];
                    int green = (rgb[2] << 8) | rgb[3];
                    int blue  = (rgb[4] << 8) | rgb[5];

                    pixels->at(x, y)->setChannel(RED, red);
                    pixels->at(x, y)->setChannel(GREEN, green);
                    pixels->at(x, y)->setChannel(BLUE, blue);
                }
            }
        }
        else {
            throw FormatException("Unsupported maxValue for binary PPM.");
        }
    } catch (...) {
        delete pixels;
        throw;
    }
}

static ImageRegistrar<PPMImage> reg_ppmImage("ppm", "Portable Pixemap format");
