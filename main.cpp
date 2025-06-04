#include <iostream>

#include "src/ImageTypes/PGMImage.hpp"
#include "src/Pixels/GrayPixel8.hpp"


int main() {
    
    PGMImage image("pgm_1.pgm");
    image.print();

    // GrayPixel8 p8(64);
    // p8.print();

    return 0;
}