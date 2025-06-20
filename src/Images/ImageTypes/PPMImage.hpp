/* File structure:

- Signature             P3 of ASCII, P6 for binary
- Width                 unsigned int
- Height                usnigned int
- max_value             Max pixel value
- List of the pixels    List of triplets ((r, g, b)) each ranging from 0 to max_value

*/
#pragma once

#include "../Image.hpp"

enum class PPMSignature {
    NONE = -1,
    P3,
    P6,
};

class PPMImage : public Image {
public:

    PPMImage();
    PPMImage(const std::string& filename);

    inline virtual Image* clone() const override { return new PPMImage(*this); }

    virtual void print(std::ostream& os = std::cout) const override;

    virtual ~PPMImage() = default;

private:
    PPMSignature signature;

private:
    void loadP3File(std::istream& is);
    void loadP6File(std::istream& is);

private: 
    enum Channels {
        RED,
        GREEN,
        BLUE,
    };
};
