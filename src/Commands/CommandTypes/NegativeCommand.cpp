#include "NegativeCommand.hpp"
#include "../CommandFactory/CommandRegistrar.hpp"

void NegativeCommand::execute() {
    std::vector<Image*> images = getSessionImages(currentSession);
    for (int i = 0; i < images.size(); i++) {
        images[i]->negative();
    }
}

Command* NegativeCommand::clone() const {
    return new NegativeCommand(*this);
}

static CommandRegistrar<NegativeCommand> reg_negative("negative");