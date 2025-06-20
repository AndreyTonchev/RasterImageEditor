#include "Session.hpp"

Session::Session() 
    : id(generateId()) {
}

// Session::Session(const Session& other) 
//     : id(generateId()) {
//     for (int i = 0; i < other.images.size(); i++) {
//         images.emplace_back(other.images[i].image->clone(), other.images[i].status);
//     }

    
    
// }

Session::~Session() {
    for (int i = 0; i < commands.size(); i++) {
        delete commands[i];
    }

    for (int i = 0; i < undoCommands.size(); i++) {
        delete undoCommands[i];
    }

    for (int i = 0; i < images.size(); i++)
    {
        delete images[i].image;
    }
    
    
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

