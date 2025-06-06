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

void Image::save(std::string& filename) const {
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
