#include "FlipCommand.hpp"
#include "../CommandFactory/CommandRegistrar.hpp"
#include "../../Session/Session.hpp"

FlipCommand::FlipCommand(Session* currentSession)
    : Command(currentSession) {
    instant = false;
}

void FlipCommand::execute() {
    std::vector<Image*>& images = currentSession->getSessionImages();
    for (int i = 0; i < images.size(); i++) {
        if (direction == "top" || direction == "bottom") {
            images[i]->transformOrientation(Orientation::MH);
        } 
        else if (direction == "right" || direction == "left") {
            images[i]->transformOrientation(Orientation::MV);
        }
    } 
}

void FlipCommand::validate() const {
    if (direction != "left" && direction != "right" && direction != "top" && direction != "bottom") {
        throw CommandException("Invalid Rotate direction. You can only rotate 'left' or 'right'.");
    } 
}

void FlipCommand::parse(const std::vector<std::string>& args) {
    if (args.size() != 1) {
        throw CommandException("Invalid arguments count passed. Expected 1");
    }

    direction = args[0];
}

static CommandRegistrar<FlipCommand> reg_negative("flip", "fli <left / right / top / bottom>\n - Morrors the image on the x or y axis");