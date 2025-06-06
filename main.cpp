#include <iostream>

#include "src/Images/ImageTypes/PGMImage.hpp"
#include "src/Images/ImageTypes/PBMImage.hpp"



int main() {
    
    PGMImage pgm1("pgm_1.pgm");
    pgm1.print();

    pgm1.negative();
    pgm1.print();

    PGMImage pgm2("pgm_1.pgm");
    pgm2.grayscale();
    pgm2.print();

    PGMImage pgm3("pgm_1.pgm");
    pgm3.monochrome();
    pgm3.print();

    // PBMImage pbm1("pbm_1.pbm");
    // pbm1.print();
    // pbm1.negative();
    // pbm1.print();

    return 0;
}