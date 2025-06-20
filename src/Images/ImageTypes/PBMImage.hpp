/* File structure:
- Signature             P1 of ASCII, P4 for Binary
- Width                 unsigned int
- Height                usnigned int
- List of the pixels    0 (black) or 1 (white)

*/

#pragma once

#include "../Image.hpp"

enum class PBMSignature {
    NONE = -1,
    P1,
    P4,
};

class PBMImage : public Image {
public:

    PBMImage();
    PBMImage(const std::string& filename);

    inline virtual Image* clone() const override { return new PBMImage(*this); }

    virtual void print(std::ostream& os = std::cout) const override;

private:
    PBMSignature signature;

private:
    void loadP1File(std::istream& is);
    void loadP4File(std::istream& is);
    
};