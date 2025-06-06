#include <iostream>

#include "src/ImageTypes/PGMImage.hpp"
#include "src/ImageTypes/PBMImage.hpp"
#include "src/Pixels/GrayPixel8.hpp"



int main() {
    
    // PGMImage image("pgm_1.pgm");
    // image.print();

    PBMImage pbm1("pbm_1.pbm");
    pbm1.print();
    pbm1.negative();
    pbm1.print();

    return 0;
}