#pragma once

#include <vector>

#include "../Images/Image.hpp"
#include "../Commands/Command.hpp"

class Session {
public:
    Session();

    bool addCommand(Command* cmd);

private:
    std::vector<Image*> images;
    std::vector<Command*> commands;
    std::vector<Command*> undoCommands;

    unsigned int id;
    
private:
    static unsigned int lastId;
    static unsigned int generateId();

    friend std::vector<Image*>& Command::getSessionImages(Session*);
};