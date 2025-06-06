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

