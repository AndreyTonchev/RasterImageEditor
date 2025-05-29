#pragma once 

class AbstractImage {
public:
    virtual ~AbstractImage() noexcept = default;
    virtual AbstractImage* clone() const = 0;

};