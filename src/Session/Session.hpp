#pragma once

#include <vector>

#include "../Images/Image.hpp"
#include "../Commands/Command.hpp"

class Session {
public:


private:
    std::vector<Image*> images;
    std::vector<Command*> commands;
    std::vector<Command*> undoCommands;

    unsigned int id;

    
private:
    static unsigned int lastID;
    static unsigned int generateID();

    friend std::vector<Image*>& Command::getSessionImages(Session&);
};