#include "Image.hpp"

Image::Image()
    : pixels(nullptr), filename(""), orientation(Orientation::R0), width(0), height(0), maxValue(0) {
}

Image::Image(const Image& other)
    : filename(other.filename), orientation(Orientation::R0), pixels(nullptr), width(other.width), height(other.height), maxValue(other.maxValue) {
    try {
        if (other.pixels) {
            pixels = other.pixels->clone();
        }
    } catch (...) {
        delete pixels;
        throw;
    } 
}

Image& Image::operator=(const Image& other) {
    if (this != &other) {
        AbstractPixelMatrix* newPixels = nullptr;
        if (other.pixels) {
            newPixels = other.pixels->clone();  // This might throw
        }

        delete pixels;
        pixels = newPixels;
        filename = other.filename;
        orientation = other.orientation;
        width = other.width;
        height = other.height;
        maxValue = other.maxValue;
    }
    return *this;
}

void Image::printPixels(std::ostream& os) const {
    switch (orientation) {
        case Orientation::R0:
            pixels->printR0(os);
            break;
        case Orientation::R90:
            pixels->printR90(os);
            break;
        case Orientation::R180:
            pixels->printR180(os);
            break;
        case Orientation::R270:
            pixels->printR270(os);
            break;
        case Orientation::MH:
            pixels->printMH(os);
            break;
        case Orientation::MV:
            pixels->printMV(os);
            break;
        case Orientation::DF:
            pixels->printDF(os);
            break;
        case Orientation::AD:
            pixels->printAD(os);
            break;
        default:
            os << "Unknown orientation\n";
            break;
    }
}

void Image::printPixelsBinary(std::ostream& os) const {
    switch (orientation) {
        case Orientation::R0:
            pixels->printR0Binary(os);
            break;
        case Orientation::R90:
            pixels->printR90Binary(os);
            break;
        case Orientation::R180:
            pixels->printR180Binary(os);
            break;
        case Orientation::R270:
            pixels->printR270Binary(os);
            break;
        case Orientation::MH:
            pixels->printMHBinary(os);
            break;
        case Orientation::MV:
            pixels->printMVBinary(os);
            break;
        case Orientation::DF:
            pixels->printDFBinary(os);
            break;
        case Orientation::AD:
            pixels->printADBinary(os);
            break;
        default:
            os << "Unknown orientation\n";
            break;
    }
}

void Image::printDimensions(std::ostream& os) const {
    if (orientation == Orientation::R90 ||
        orientation == Orientation::R270 ||
        orientation == Orientation::DF || 
        orientation == Orientation::AD) {
        os << pixels->getHeight() << ' ' << pixels->getWidth() << std::endl;
    }
    else {
        os << pixels->getWidth() << ' ' << pixels->getHeight() << std::endl;
    }
}

void Image::negative() {
    pixels->negative();
}

void Image::grayscale() {
    pixels->grayscale();
}

void Image::monochrome() {
    pixels->monochrome();
}

std::size_t Image::getWidth() const {
    return width;
}    

std::size_t Image::getHeight() const {
    return height;
}    

std::size_t Image::getMaxValue() const {
    return maxValue;
}

std::string Image::getFilename() const {
    return filename;
}

AbstractPixel* Image::at(std::size_t w, std::size_t h) {
    return pixels->at(w,h);
}

const AbstractPixel* Image::at(std::size_t w, std::size_t h) const {
    return pixels->at(w,h);
}

bool Image::resize(std::size_t newWidth, std::size_t newHeight) {
    pixels->resize(newWidth, newHeight);

    height = newHeight;
    width = newWidth;
    return true;
}

using O = Orientation;

void Image::transformOrientation(Orientation apply) {
    orientation = orientationTable[static_cast<int>(orientation)][static_cast<int>(apply)];
}

void Image::skipComments(std::istream& is) {
    char ch;
    while (is >> std::ws, is.peek() == '#') {
        is.get(ch);
        std::string temp;
        std::getline(is, temp);
    }
}

Orientation Image::orientationTable[8][8] = {
    //        |   R0   |  R90   |  R180  |  R270  |   MH   |   MV   |   DF   |   AD   |
    /* R0  */ { O::R0,   O::R90,  O::R180, O::R270, O::MH,   O::MV,   O::DF,   O::AD },
    /* R90 */ { O::R90,  O::R180, O::R270, O::R0,   O::AD,   O::DF,   O::MV,   O::MH },
    /* R180*/ { O::R180, O::R270, O::R0,   O::R90,  O::MV,   O::MH,   O::AD,   O::DF },
    /* R270*/ { O::R270, O::R0,   O::R90,  O::R180, O::DF,   O::AD,   O::MH,   O::MV },
    /* MH  */ { O::MH,   O::AD,   O::MV,   O::DF,   O::R0,   O::R180, O::R270, O::R90 },
    /* MV  */ { O::MV,   O::DF,   O::MH,   O::AD,   O::R180, O::R0,   O::R90,  O::R270 },
    /* DF  */ { O::DF,   O::MV,   O::AD,   O::MH,   O::R270, O::R90,  O::R0,   O::R180 },
    /* AD  */ { O::AD,   O::MH,   O::DF,   O::MV,   O::R90,  O::R270, O::R180, O::R0 }      
};
