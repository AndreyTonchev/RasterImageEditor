#include "GrayscaleCommand.hpp"
#include "../CommandFactory/CommandRegistrar.hpp"

GrayscaleCommand::GrayscaleCommand(Session* currentSession) 
    : Command(currentSession) {

}

void GrayscaleCommand::execute() {
    std::vector<Image*> images = getSessionImages(currentSession);
    for (int i = 0; i < images.size(); i++) {
        images[i]->grayscale();
    }
}

void GrayscaleCommand::validate() const {

}

void GrayscaleCommand::parse(const std::vector<std::string>& args) {

}

static CommandRegistrar<GrayscaleCommand> reg_grayscale("grayscale");