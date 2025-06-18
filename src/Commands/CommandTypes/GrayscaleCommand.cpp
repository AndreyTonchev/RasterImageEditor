#include "GrayscaleCommand.hpp"
#include "../CommandFactory/CommandRegistrar.hpp"

void GrayscaleCommand::execute() {
    std::vector<Image*> images = getSessionImages(currentSession);
    for (int i = 0; i < images.size(); i++) {
        images[i]->grayscale();
    }
}

void GrayscaleCommand::parse(const std::vector<std::string>& args) {

}

Command* GrayscaleCommand::clone() const {
    return new GrayscaleCommand(*this);
}

static CommandRegistrar<GrayscaleCommand> reg_grayscale("grayscale");