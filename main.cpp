#include <iostream>

#include "src/Images/AllImages.hpp"
#include "src/utils/Utils.hpp"
#include "src/Commands/AllComands.hpp"

#include "src/Session/SessionManager.hpp"



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

        SessionManager::getInstance().run();

        // std::cout << Utils::getExtension("Filen.ame.hpp");

        // PPMImage ppm1("media/PPM_P3.ppm");
        // ppm1.negative();
        // ppm1.save("media/negative.ppm");
        
        // PPMImage ppm2("media/PPM_P3.ppm");
        // ppm2.monochrome();
        // ppm2.save("media/monochrome.ppm");

        // PPMImage ppm3("media/PPM_P3.ppm");
        // ppm3.grayscale();
        // ppm3.save("media/grayscale.ppm");
        
    } catch (const std::exception& e) { 
        std::cerr << e.what();
    }

    return 0;
}