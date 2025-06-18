#include "GrayscaleCommand.hpp"
#include "../CommandFactory/CommandRegistrar.hpp"

GrayscaleCommand::GrayscaleCommand(Session* currentSession) 
    : Command(currentSession) {
    instant = false;

}

void GrayscaleCommand::execute() {
    std::vector<Image*> images = getSessionImages(currentSession);
    for (int i = 0; i < images.size(); i++) {
        images[i]->grayscale();
    }
}

static CommandRegistrar<GrayscaleCommand> reg_grayscale("grayscale", "Converts all images to shades of gray, removing all color information.");