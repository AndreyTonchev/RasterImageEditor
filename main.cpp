#include <iostream>

#include "src/ImageTypes/PGMImage.hpp"
#include "src/ImageTypes/PBMImage.hpp"
#include "src/Pixels/GrayPixel8.hpp"



int main() {
    
    PGMImage pgm1("pgm_1.pgm");
    pgm1.print();
    pgm1.negative();
    pgm1.print();

    // PBMImage pbm1("pbm_1.pbm");
    // pbm1.print();
    // pbm1.negative();
    // pbm1.print();

    return 0;
}