#include "MonochromeCommand.hpp"
#include "../CommandFactory/CommandRegistrar.hpp"
#include "../../Session/Session.hpp"

MonochromeCommand::MonochromeCommand(Session* currentSession) 
    : Command(currentSession) {
    instant = false;
}

void MonochromeCommand::execute() {
    std::vector<Session::SessionImage>& images = currentSession->getSessionImages();
    for (int i = 0; i < images.size(); i++) {
        if (images[i].status != Session::Status::PendingLoad) {
            images[i].image->monochrome();
            images[i].status == Session::Status::Modified;
        }
    }
}

static CommandRegistrar<MonochromeCommand> reg_monochrome("monochrome", "Converts all images to pure black and white.");