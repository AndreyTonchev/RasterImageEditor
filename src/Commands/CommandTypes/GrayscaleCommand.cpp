#include "GrayscaleCommand.hpp"
#include "../CommandFactory/CommandRegistrar.hpp"
#include "../../Session/Session.hpp"

GrayscaleCommand::GrayscaleCommand(Session* currentSession) 
    : Command(currentSession) {
    instant = false;

}

void GrayscaleCommand::parse(const std::vector<std::string>& parse) {
    if (!currentSession) {
        throw CommandException("No active session.");
    }

    setModifiedStatus();
}

void GrayscaleCommand::execute() {
    std::vector<Session::SessionImage>& images = currentSession->getSessionImages();
    for (int i = 0; i < images.size(); i++) {
        if (images[i].status != Session::Status::PendingLoad) {
            images[i].image->grayscale();
        }
    }
}

static CommandRegistrar<GrayscaleCommand> reg_grayscale("grayscale", "Converts all images to shades of gray, removing all color information.");