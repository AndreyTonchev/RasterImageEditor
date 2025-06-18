#include "Session.hpp"

Session::Session() 
    : id(generateId()) {
}

std::vector<Image*>& Command::getSessionImages(Session* s) {
    return s->images; // Accessing private member of Session
}

bool Session::addCommand(Command* cmd) {
    commands.push_back(cmd);
    return true;
}

unsigned int Session::lastId = 1;

unsigned int Session::generateId() {
    return lastId++;
}

