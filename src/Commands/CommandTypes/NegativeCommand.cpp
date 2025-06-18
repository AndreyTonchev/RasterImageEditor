#include "NegativeCommand.hpp"
#include "../CommandFactory/CommandRegistrar.hpp"

NegativeCommand::NegativeCommand(Session* currentSession) 
    : Command(currentSession) {
    instant = false;

}

void NegativeCommand::execute() {
    std::vector<Image*> images = getSessionImages(currentSession);
    for (int i = 0; i < images.size(); i++) {
        images[i]->negative();
    }
}

static CommandRegistrar<NegativeCommand> reg_negative("negative", "Inverts the colors of all images in the current session.");