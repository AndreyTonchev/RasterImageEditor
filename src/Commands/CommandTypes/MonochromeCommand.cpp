#include "MonochromeCommand.hpp"
#include "../CommandFactory/CommandRegistrar.hpp"

void MonochromeCommand::execute() {
    std::vector<Image*> images = getSessionImages(currentSession);
    for (int i = 0; i < images.size(); i++) {
        images[i]->monochrome();
    }
}

Command* MonochromeCommand::clone() const {
    return new MonochromeCommand(*this);
}

static CommandRegistrar<MonochromeCommand> reg_monochrome("monochrome");