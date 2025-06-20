#pragma once

#include "../Image.hpp"


class ImageBase {
public:
    virtual ~ImageBase() = default;
    virtual Image* create(const std::string& filename) const = 0;
    
};

