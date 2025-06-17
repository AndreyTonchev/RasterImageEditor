#include "Image.hpp"

Image::Image()
    : pixels(nullptr), filename("") {
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
    return pixels->getWidth();
}    


std::size_t Image::getHeight() const {
    return pixels->getHeight();
}    

void Image::save(const std::string& filename) const {
    if (filename == "") {
        throw FileException("Bad File Name.");
    }

    std::ofstream file(filename);
    if (!file) {
        throw FileException("Error opening file for writing.");
    }

    this->print(file); // need to check if file is ok
    file.close();
}

using O = Image::Orientation;

Image::Orientation Image::orientationTable[8][8] = {
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
