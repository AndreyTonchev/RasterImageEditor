#include "Image.hpp"

Image::Image()
    : pixels(nullptr), filename("") {
}

void Image::grayscale() {

}

void Image::negative() {

}



std::size_t Image::getWidth() const {
    return pixels->getWidth();
}    


std::size_t Image::getHeight() const {
    return pixels->getHeight();
}    

