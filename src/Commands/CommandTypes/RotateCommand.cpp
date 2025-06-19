#include "RotateCommand.hpp"
#include "../CommandFactory/CommandRegistrar.hpp"
#include "../../Session/Session.hpp"

RotateCommand::RotateCommand(Session* currentSession)
    : Command(currentSession) {
    instant = false;
}

void RotateCommand::execute() {
    std::vector<Session::SessionImage>& images = currentSession->getSessionImages();
    for (int i = 0; i < images.size(); i++) {
        if (images[i].status != Session::Status::PendingLoad) {
            if (direction == "left") {
                images[i].image->transformOrientation(Orientation::R90);
            } 
            else if (direction == "right") {
                images[i].image->transformOrientation(Orientation::R270);
            }
            
            images[i].status = Session::Status::Modified;
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