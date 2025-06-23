#pragma once

#include "../Image.hpp"

class BMPImage : public Image {
public:
    BMPImage();
    BMPImage(const std::string& filename);

    virtual Image* clone() const override;
    virtual void save(const std::string& filename) override {}
    virtual ~BMPImage() { delete pixels; };

private:
    #pragma pack(push, 1)

    struct BitmapFileHeader {
        uint16_t type;       
        uint32_t size;
        uint16_t reserved1;
        uint16_t reserved2;
        uint32_t offBits;    
    };

    struct DIBHeader40 {
        uint32_t size;          
        int32_t  width;
        int32_t  height;
        uint16_t planes;
        uint16_t bitCount;
        uint32_t compression;
        uint32_t sizeImage;
        int32_t  xPelsPerMeter;
        int32_t  yPelsPerMeter;
        uint32_t clrUsed;
        uint32_t clrImportant;
    };

    #pragma pack(pop)
private:

    BitmapFileHeader fileHeader;
    DIBHeader40 dibHeader40;
    int bitsPerPixel;
    AbstractPixelMatrix* pixels;

    void printMetadata(std::ostream& os = std::cout) const;

    void load24(std::ifstream& is);

private:
    enum Channels {
        BLUE,   ///< Blue channel index.
        GREEN,  ///< Green channel index.
        RED     ///< Red channel index.
    };
};
