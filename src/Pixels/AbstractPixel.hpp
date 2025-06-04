#pragma once

class AbstractPixel {
public:
    virtual ~AbstractPixel() = default;

    virtual AbstractPixel* clone() const = 0;
    virtual AbstractPixel* negative() const = 0;
    virtual AbstractPixel* grayscale() const = 0;

    virtual void setChannel(size_t channel, uint32_t value) = 0;
    virtual uint32_t getChannel(size_t channel) const = 0;

    virtual void print(std::ostream& = std::cout) const = 0;

    inline friend std::ostream& operator<<(std::ostream& os, AbstractPixel* pixel) {
        pixel->print(os);
        return os;
    }
private:
};