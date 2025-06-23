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

void PPMImage::print(std::ostream& os) {
    std::string signatureStr = (signature == PPMSignature::P3) ? "P3" : "P6";

    os << signatureStr << std::endl;
    printDimensions(os);
    os << maxValue << std::endl;
    if (signatureStr == "P3") {
        printPixels(os);
    } else {
        saveP6File(os);
    }
    
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
    // is.ignore();

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

void PPMImage::saveP6File(std::ostream& os) {
    if (maxValue <= 255) {
        for (std::size_t y = 0; y < height; ++y) {
            for (std::size_t x = 0; x < width; ++x) {
                auto pixel = pixels->at(x, y);
                unsigned char rgb[3] = {
                    static_cast<unsigned char>(pixel->getChannel(RED)),
                    static_cast<unsigned char>(pixel->getChannel(GREEN)),
                    static_cast<unsigned char>(pixel->getChannel(BLUE))
                };
                os.write(reinterpret_cast<char*>(rgb), 3);
            }
        }
    } else if (maxValue <= 65535) {
        for (std::size_t y = 0; y < height; ++y) {
            for (std::size_t x = 0; x < width; ++x) {
                auto pixel = pixels->at(x, y);
                uint16_t r = pixel->getChannel(RED);
                uint16_t g = pixel->getChannel(GREEN);
                uint16_t b = pixel->getChannel(BLUE);

                unsigned char rgb[6] = {
                    static_cast<unsigned char>((r >> 8) & 0xFF),
                    static_cast<unsigned char>(r & 0xFF),
                    static_cast<unsigned char>((g >> 8) & 0xFF),
                    static_cast<unsigned char>(g & 0xFF),
                    static_cast<unsigned char>((b >> 8) & 0xFF),
                    static_cast<unsigned char>(b & 0xFF)
                };

                os.write(reinterpret_cast<char*>(rgb), 6);
            }
        }
    }
}

static ImageRegistrar<PPMImage> reg_ppmImage("ppm", "Portable Pixemap format");
