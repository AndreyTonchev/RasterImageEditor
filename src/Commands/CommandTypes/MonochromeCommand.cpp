#include "MonochromeCommand.hpp"
#include "../CommandFactory/CommandRegistrar.hpp"
#include "../../Session/Session.hpp"

MonochromeCommand::MonochromeCommand(Session* currentSession) 
    : Command(currentSession) {
    instant = false;
}

void MonochromeCommand::parse(const std::vector<std::string>& args) {
    if (!currentSession) {
        throw CommandException("No active session.");
    }

    setModifiedStatus();
}

void MonochromeCommand::execute() {
    std::vector<Session::SessionImage>& images = currentSession->getSessionImages();
    for (int i = 0; i < images.size(); i++) {
        if (images[i].status != Session::Status::PendingLoad) {
            images[i].image->monochrome();
        }
    }
}

static CommandRegistrar<MonochromeCommand> reg_monochrome("monochrome", "monochrome - Converts all images to pure black and white.");