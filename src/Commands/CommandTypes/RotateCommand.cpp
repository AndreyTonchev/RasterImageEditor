#include "RotateCommand.hpp"
#include "../CommandFactory/CommandRegistrar.hpp"
#include "../../Session/Session.hpp"

RotateCommand::RotateCommand(Session* currentSession)
    : Command(currentSession) {
    instant = false;
}

void RotateCommand::execute() {
    std::vector<Image*>& images = currentSession->getSessionImages();
    for (int i = 0; i < images.size(); i++) {
        if (direction == "left") {
            images[i]->transformOrientation(Orientation::R90);
        } 
        else if (direction == "right") {
            images[i]->transformOrientation(Orientation::R270);
        }
    } 
}

void RotateCommand::validate() const {
    if (direction != "left" && direction != "right") {
        throw CommandException("Invalid Rotate direction. You can only rotate 'left' or 'right'.");
    } 
}

void RotateCommand::parse(const std::vector<std::string>& args) {
    if (args.size() != 1) {
        throw CommandException("Invalid arguments count passed. Expected 1");
    }

    direction = args[0];
}

static CommandRegistrar<RotateCommand> reg_negative("rotate", "rotate <left / right> - Rotates the Image 90deg left or right");