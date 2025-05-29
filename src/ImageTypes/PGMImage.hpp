/* File structure:

- Signature             P2 of ASCII, P5 for binary
- Width                 unsigned int
- Height                usnigned int
- max_value             Max pixel value
- List of the pixels    0 (black), max_value (white) or anything in between

*/

#pragma once

#include "../main/Image.hpp"

enum Signature {
    P2, P5, None
};

class PGMImage : public Image {
public:

    PGMImage();
    PGMImage(const std::string& filename);
    // PGMImage(const Image& other);
    // PGMImage& operator=(const Image& other);
    // virtual ~PGMImage();

    virtual void load() const override;
    virtual void save(const std::string& outputFilename = "") const override;

    inline virtual Image* clone() const override { return new PGMImage(*this); }
    
    virtual void print(std::ostream& os = std::cout) const;

private:
    Signature signature;
    int maxValue;

private:

    void loadP2File(std::ifstream& is);
    void loadP5File(std::ifstream& is);
};