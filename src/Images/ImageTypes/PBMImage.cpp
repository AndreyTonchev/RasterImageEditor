#include "PBMImage.hpp"
#include "../ImageFactory/ImageRegistrar.hpp"
#include "../../Pixels/PixelTypes/MonoPixel8.hpp"
#include "../PixelMatrix.hpp"


PBMImage::PBMImage() 
    : Image(), signature(PBMSignature::NONE) {
    maxValue = 1;
}

PBMImage::PBMImage(const std::string& filename) {
    std::ifstream file;
    this->filename = filename;
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

void PBMImage::save(const std::string& filename) {
    if (filename == "") {
        throw FileException("Bad File Name.");
    }   
    
    std::ofstream file;
    if (signature == PBMSignature::P1 || signature == PBMSignature::P4) {
        file.open(filename);
        if (!file) {
            throw FileException("Failed to open file for writing: " + filename);
        }

        file << "P1\n";
        printDimensions(file);
        printPixelsBinary(file);
    } 
    else if (signature == PBMSignature::P4) {   
        file.open(filename, std::ios::binary);
        if (!file) {
            throw FileException("Failed to open file for writing: " + filename);
        }

        file << "P4\n";
        printDimensions(file);
        for (std::size_t y = 0; y < height; ++y) {
            unsigned char byte = 0;
            int bitPos = 7;

            for (std::size_t x = 0; x < width; ++x) {
                int pixelVal = pixels->at(x, y)->getChannel(MONO);

                if (pixelVal != 0) {
                    byte |= (1 << bitPos);
                }

                bitPos--;

                if (bitPos < 0 || x == width - 1) {
                    file.write(reinterpret_cast<char*>(&byte), 1);
                    byte = 0;
                    bitPos = 7;
                }
            }
        }
    }

    file.close();
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
                pixels->at(x,y)->setChannel(MONO, pixelValue);
            }
        }

    } catch (...) {
        delete pixels;
        throw;
    }
}

void PBMImage::loadP4File(std::istream& is) {
    try {
        pixels = new PixelMatrix<MonoPixel8>(width, height, 1);

        std::size_t rowBytes = (width + 7) / 8;
        std::vector<unsigned char> buffer(rowBytes);

        for (std::size_t y = 0; y < height; ++y) {
            if (!is.read(reinterpret_cast<char*>(buffer.data()), rowBytes)) {
                throw FileException("Failed to read P4 row data.");
            }

            for (std::size_t x = 0; x < width; ++x) {
                std::size_t byteIndex = x / 8;
                std::size_t bitIndex = 7 - (x % 8);

                unsigned char byte = buffer[byteIndex];
                int value = (byte >> bitIndex) & 1;

                pixels->at(x, y)->setChannel(MONO, value);
            }
        }
    } catch (...) {
        delete pixels;
        throw;
    }
}

static ImageRegistrar<PBMImage> reg_pbmImage("pbm", "Portable Bit Map");