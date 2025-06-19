#include "MonochromeCommand.hpp"
#include "../CommandFactory/CommandRegistrar.hpp"
#include "../../Session/Session.hpp"

MonochromeCommand::MonochromeCommand(Session* currentSession) 
    : Command(currentSession) {
    instant = false;
}

void MonochromeCommand::execute() {
    std::vector<Image*>& images = currentSession->getSessionImages();
    for (int i = 0; i < images.size(); i++) {
        images[i]->monochrome();
    }
}

static CommandRegistrar<MonochromeCommand> reg_monochrome("monochrome", "Converts all images to pure black and white.");