/* File structure:

- Signature             P2 of ASCII, P5 for binary
- Width                 unsigned int
- Height                usnigned int
- max_value             Max pixel value
- List of the pixels    0 (black), max_value (white) or anything in between

*/

#pragma once

#include "../Image.hpp"
#include "../ImageFactory/ImageRegistrar.hpp"


enum class PGMSignature {
    NONE = -1, 
    P2, 
    P5,
};

class PGMImage : public Image {
public:

    PGMImage();
    PGMImage(const std::string& filename);

    inline virtual Image* clone() const override { return new PGMImage(*this); }
    
    virtual void print(std::ostream& os = std::cout) const override;

private:
    PGMSignature signature;
    int maxValue;
    int height;
    int width;

private:
    void loadP2File(std::istream& is);
    void loadP5File(std::istream& is);

private:
    enum Channels {
        GRAY
    };
};

static ImageRegistrar<PGMImage> reg_pgmImage("pgm", "Portable Graymap format");