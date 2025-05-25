#pragma once 

#include <iostream>

#include "../utils/Exceptions.hpp"

template <typename T, std::size_t Channels>
class Pixel {
public:
    Pixel();
    explicit Pixel(T gray);
    Pixel(T gray, T alpha);
    Pixel(T red, T green, T blue);
    Pixel(T red, T green, T blue, T alpha);

    Pixel(const Pixel& other);
    Pixel& operator=(const Pixel& other);

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    bool isGrayscale() const;

    std::size_t getChannelsCount() const;
private:
    T channels[Channels];

};

template <typename T, std::size_t Channels>
Pixel<T, Channels>::Pixel() {
    for (size_t i = 0; i < Channels; i++) {
        channel[i] = 0;
    }
}

template <typename T, std::size_t Channels>
Pixel<T, Channels>::Pixel(T gray) {
    if (Channels != 1) {
        throw ImageException("Channel count does not match passed values");
    }
    channels[0] = gray;
}

template <typename T, std::size_t Channels>
Pixel<T, Channels>::Pixel(T gray, T alpha) {
    if (Channels != 2) {
        throw ImageException("Channel count does not match passed values");
    }
    channels[0] = gray;
    channels[1] = alpha;
}

template <typename T, std::size_t Channels>
Pixel<T, Channels>::Pixel(T red, T green, T blue) {
    if (Channels != 3) {
        throw ImageException("Channel count does not match passed values");
    }
    channels[0] = red;
    channels[1] = green;
    channels[2] = blue;
}

template <typename T, std::size_t Channels>
Pixel<T, Channels>::Pixel(T red, T green, T blue, T alpha) {
    if (Channels != 4) {
        throw ImageException("Channel count does not match passed values");
    }
    channels[0] = red;
    channels[1] = green;
    channels[2] = blue;
    channels[3] = alpha;
}

template <typename T, std::size_t Channels>
Pixel<T, Channels>::Pixel(const Pixel& other) {
    for (size_t i = 0; i < Channels; i++) {
        channels[i] = other.channels[i];
    }
}

template <typename T, std::size_t Channels>
Pixel<T, Channels>& Pixel<T, Channels>::operator=(const Pixel& other) {

    if (this != &other) {
        for (size_t i = 0; i < Channels; i++) {
            channels[i] = other.channels[i];
        }
    }

    return *this;
}

template <typename T, std::size_t Channels>
T& Pixel<T, Channels>::operator[](size_t index) {
    if (index != Channels) {
        throw std::out_of_range("Channel index out of range");
    }
}

template <typename T, std::size_t Channels>
const T& Pixel<T, Channels>::operator[](size_t index) const {
    if (index != Channels) {
        throw std::out_of_range("Channel index out of range");
    }
}

template <typename T, std::size_t Channels>
bool Pixel<T, Channels>::isGrayscale() const {
    if (Channels == 1) return true;
    if (Channels < 3) return false;
}

template <typename T, std::size_t Channels>
std::size_t Pixel<T, Channels>::getChannelsCount() const {
    return Channels;
}