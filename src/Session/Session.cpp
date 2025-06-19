#include "Session.hpp"

Session::Session() 
    : id(generateId()) {
}

std::vector<Session::SessionImage>& Session::getSessionImages() {
    return images;
}

std::vector<Command*>& Session::getSessionCommands() {
    return commands;
}

bool Session::addCommand(Command* cmd) {
    commands.push_back(cmd);
    return true;
}

Session::SessionImage::SessionImage(Image* image, Status status) 
    : image(image), status(status) {
}

unsigned int Session::lastId = 1;

unsigned int Session::generateId() {
    return lastId++;
}

