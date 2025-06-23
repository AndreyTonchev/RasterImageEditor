#include "NegativeCommand.hpp"
#include "../CommandFactory/CommandRegistrar.hpp"
#include "../../Session/Session.hpp"

NegativeCommand::NegativeCommand(Session* currentSession) 
    : Command(currentSession) {
    instant = false;

}

void NegativeCommand::parse(const std::vector<std::string>& parse) {
    if (!currentSession) {
        throw CommandException("No active session.");
    }

    setModifiedStatus();
}

void NegativeCommand::execute() {
        std::vector<Session::SessionImage>& images = currentSession->getSessionImages();
    for (int i = 0; i < images.size(); i++) {
        if (images[i].status != Session::Status::PendingLoad) {
            images[i].image->negative();
        }
    }
}

static CommandRegistrar<NegativeCommand> reg_negative("negative", "Inverts the colors of all images in the current session.");