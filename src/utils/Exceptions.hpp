#pragma once

#include <stdexcept>
#include <string>

class ImageException : public std::exception {
protected:
    std::string message;

public:
    ImageException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

class FileException : public ImageException {
public:
    FileException(const std::string& msg) : ImageException("File Error: " + msg) {}
};

class FormatException : public ImageException {
public:
    FormatException(const std::string& msg) : ImageException("Format Error: " + msg) {}
};

class SessionException : public ImageException {
public:
    SessionException(const std::string& msg) : ImageException("Session Error: " + msg) {}
};