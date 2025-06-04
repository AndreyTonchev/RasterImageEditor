#pragma once 

class AbstractImage {
public:
    virtual ~AbstractImage() noexcept = default;
    virtual AbstractImage* clone() const = 0;
    virtual void grayscale() = 0;
    virtual void negative() = 0;

};