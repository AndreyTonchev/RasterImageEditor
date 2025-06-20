#pragma once

#include <string>

#include "ImageBase.hpp"
#include "ImageFactory.hpp"


template <typename T>
class ImageRegistrar : public ImageBase {
public:
    ImageRegistrar(const std::string& name, const std::string& description);
    Image* create(const std::string& filename) const;

};

template <typename T>
ImageRegistrar<T>::ImageRegistrar(const std::string& name, const std::string& description) {
    ImageFactory::registerImage(name, description, this);
}

template <typename T>
Image* ImageRegistrar<T>::create(const std::string& filename) const {
    return new T(filename);
}