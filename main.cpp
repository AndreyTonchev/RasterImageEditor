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
        std::string filename1("negative.ppm");
        std::string filename2("monochrome.ppm");
        std::string filename3("grayscale.ppm");

        
        PPMImage ppm1("PPM_P3.ppm");
        ppm1.negative();
        ppm1.save(filename1);
        
        PPMImage ppm2("PPM_P3.ppm");
        ppm2.monochrome();
        ppm2.save(filename2);

        PPMImage ppm3("PPM_P3.ppm");
        ppm3.grayscale();
        ppm3.save(filename3);


    } catch (...) { 
        // TODO
    }

    return 0;
}