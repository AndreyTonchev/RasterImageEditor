#include <iostream>

#include "src/Images/ImageTypes/PGMImage.hpp"
#include "src/Images/ImageTypes/PBMImage.hpp"
#include "src/Images/ImageTypes/PPMImage.hpp"



int main() {
    
    // PGMImage pgm1("pgm_1.pgm");
    // pgm1.print();

    // pgm1.negative();
    // pgm1.print();

    // PGMImage pgm2("pgm_1.pgm");
    // pgm2.grayscale();
    // pgm2.print();

    // PGMImage pgm3("pgm_1.pgm");
    // pgm3.monochrome();
    // pgm3.print();

    // PBMImage pbm1("pbm_1.pbm");
    // pbm1.print();
    // pbm1.negative();
    // pbm1.print();

    
    try {
        PPMImage ppm1("ppm_1.ppm");
        ppm1.print();

        PPMImage ppm2("ppm_1.ppm");
        ppm2.negative();
        ppm2.print();

        PPMImage ppm3("ppm_1.ppm");
        ppm3.grayscale();
        ppm3.print();

        PPMImage ppm4("ppm_1.ppm");
        ppm4.monochrome();
        ppm4.print();

    } catch (const std::exception& e) { 
        std::cout << e.what();
    }

    return 0;
}