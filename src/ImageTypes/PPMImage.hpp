/* File structure:

- Signature             P3 of ASCII, P6 for binary
- Width                 unsigned int
- Height                usnigned int
- max_value             Max pixel value
- List of the pixels    List of triplets ((r, g, b)) each ranging from 0 to max_value

*/
#pragma once

#include <string>

#include "../main/AbstractImage.hpp"

class PPMImage : public AbstractImage {
public:
    PPMImage(const std::string& filename);
    void load() override;
    void save(const std::string& filename = "") override;
    void print(std::ostream& os = std::cout) const override;
    AbstractImage* clone() const override;

private:
    std::string filename;
    AbstractImage* image;
};
    