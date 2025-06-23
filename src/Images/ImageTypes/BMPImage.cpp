#include "BMPImage.hpp"
#include "../../Pixels/PixelTypes/BGRPixel8.hpp"
#include "../ImageFactory/ImageRegistrar.hpp"
#include "../PixelMatrix.hpp"


BMPImage::BMPImage() : Image() {}

Image* BMPImage::clone() const { 
    return new BMPImage(*this); 
}



// void BMPImage::print(std::ostream& os) {

//     const int rowSize = (width * 3 + 3) & ~3;
//     const uint32_t imageSize = rowSize * height;
//     const uint32_t fileSize = 14 + 40 + imageSize;

//     // === FILE HEADER ===
//     BitmapFileHeader fileHeader;
//     fileHeader.size = fileSize;
//     fileHeader.offBits = 54;

//     // === DIB HEADER ===
//     DIBHeader40 dibHeader;
//     dibHeader.width = width;
//     dibHeader.height = height; // for bottom-up, or -height for top-down
//     dibHeader.bitCount = 24;
//     dibHeader.size = imageSize;

//     // === Write headers ===
//     os.write(reinterpret_cast<const char*>(&fileHeader), sizeof(fileHeader));
//     os.write(reinterpret_cast<const char*>(&dibHeader), sizeof(dibHeader));

//     // === Write pixel data ===
//     uint8_t padding[3] = {0, 0, 0};
//     int padSize = rowSize - width * 3;

// }

BMPImage::BMPImage(const std::string& filename) {
    this->filename = filename;
    std::ifstream file;

    
    try {
        if (filename == "") {
            throw FileException("Bad FIle Name");
        }

        file.open(filename, std::ios::binary);
        if (!file) {
            throw FileException("Error Opening file for reading");
        }

        file.read(reinterpret_cast<char*>(&fileHeader), sizeof(fileHeader));
        if (fileHeader.type != 0x4D42) { // 'BM'
            throw FileException("Not a valid BMP file");
        }
        
        if (!file.read(reinterpret_cast<char*>(&dibHeader40), sizeof(dibHeader40))) {
            throw FileException("Failed to read DIB header");
        }

        if (dibHeader40.size != 40 && dibHeader40.size != 108 && dibHeader40.size != 124) {
            throw FormatException("Unsupported DIB header size");
        }

        if (dibHeader40.size > sizeof(dibHeader40)) {
            file.seekg(dibHeader40.size - sizeof(dibHeader40), std::ios::cur);
        }

        width = dibHeader40.width;
        height = std::abs(dibHeader40.height);
        bitsPerPixel = dibHeader40.bitCount;
        this->orientation = (dibHeader40.height < 0) ? Orientation::R180 : Orientation::R0;
    

        if (dibHeader40.planes != 1) {
            throw FormatException("Unsupported number of planes");
        }
        if (dibHeader40.compression != 0) { // BI_RGB = no compression
            throw FormatException("Compressed BMP files not supported");
        }
        
        printMetadata();

        if (bitsPerPixel == 24) {
            pixels = new PixelMatrix<BGRPixel8>(width, std::abs(height), 255);
            load24(file);
        }
        else if (bitsPerPixel == 8 ) {
            std::cout << "8";
        }
        else if (bitsPerPixel == 16) {
            std::cout << "16";
        }
        else if (bitsPerPixel == 32) {
            std::cout << "32";
        } 
        else {
            throw FormatException("Unsuported bits per Pixel");
        }
        file.close();

    } catch (...) {
        file.close();
        throw;
    }

}

void BMPImage::printMetadata(std::ostream& os) const {
    os << "=== BMP File Header ===\n";
    os << "Signature: " << char(fileHeader.type & 0xFF)
       << char((fileHeader.type >> 8) & 0xFF) << "\n";
    os << "File Size: " << fileHeader.size << " bytes\n";
    os << "Reserved1: " << fileHeader.reserved1 << "\n";
    os << "Reserved2: " << fileHeader.reserved2 << "\n";
    os << "Data Offset: " << fileHeader.offBits << " bytes\n\n";

    os << "=== BMP Info Header ===\n";
    os << "Header Size: " << dibHeader40.size << " bytes\n";
    os << "Width: " << dibHeader40.width << " px\n";
    os << "Height: " << dibHeader40.height << " px\n";
    os << "Planes: " << dibHeader40.planes << "\n";
    os << "Bits per Pixel: " << dibHeader40.bitCount << "\n";
    os << "Compression: " << dibHeader40.compression << "\n";
    os << "Image Size: " << dibHeader40.sizeImage << " bytes\n";
    os << "X Pixels per Meter: " << dibHeader40.xPelsPerMeter << "\n";
    os << "Y Pixels per Meter: " << dibHeader40.yPelsPerMeter << "\n";
    os << "Colors Used: " << dibHeader40.clrUsed << "\n";
    os << "Important Colors: " << dibHeader40.clrImportant << "\n";
}


void BMPImage::load24(std::ifstream& is) {
    is.seekg(fileHeader.offBits, std::ios::beg);

    int rowSize = ((bitsPerPixel * width + 31) / 32) * 4;
    int rowBytes = width * 3; 
    int padding = rowSize - rowBytes;

    bool bottomUp = (dibHeader40.height > 0);
    int h = height;


    for (int i = 0; i < h; ++i) {
        for (int col = 0; col < width; ++col) {
            uint8_t blue, green, red;
            is.read(reinterpret_cast<char*>(&blue), 1);
            is.read(reinterpret_cast<char*>(&green), 1);
            is.read(reinterpret_cast<char*>(&red), 1);

            pixels->at(i, col)->setChannel(BLUE, blue);
            pixels->at(i, col)->setChannel(GREEN, green);
            pixels->at(i, col)->setChannel(RED, red);

        }

        // Skip padding
        is.seekg(padding, std::ios::cur);
    }
}


static ImageRegistrar<BMPImage> reg_ppmImage("bmp", "Bitmap");