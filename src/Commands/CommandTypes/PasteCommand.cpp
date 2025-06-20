#include "PasteCommand.hpp"
#include "../../Session/Session.hpp"
#include "../CommandFactory/CommandRegistrar.hpp"

#include <cmath>


PasteCommand::PasteCommand(Session* currentSession)
    : Command(currentSession) {
    instant = false;
}

void PasteCommand::parse(const std::vector<std::string>& args) {
    if (!currentSession) {
        throw CommandException("No active session.");
    }

    if (args.size() != 4) {
        throw CommandException("Invalid Argument Count");
    }

    std::vector<Session::SessionImage>& images = currentSession->getSessionImages();

    for (size_t i = 0; i < images.size(); i++) {
        if (args[0] == images[i].image->getFilename()) {
            srcImage = images[i].image;
            break;
        }
    }

    for (size_t i = 0; i < images.size(); i++) {
        if (args[1] == images[i].image->getFilename()) {
            destImage = images[i].image;
            break;
        }
    }
    
    posX = std::stoi(args[2]);
    posY = std::stoi(args[3]);

    setModifiedStatus();
}

void PasteCommand::validate() const {

}
 
void PasteCommand::execute() {

    std::size_t srcWidth = srcImage->getWidth();
    std::size_t srcHeight = srcImage->getHeight();

    std::size_t destWidth = destImage->getWidth();
    std::size_t destHeight = destImage->getHeight();



    int newWidth = 
        (destWidth > posX + srcWidth) ? destWidth : posX + srcWidth;

    int newHeight = 
        (destHeight > posY + srcHeight) ? destHeight : posY + srcHeight;

    std::vector<Session::SessionImage>& images = currentSession->getSessionImages();
    destImage->resize(newWidth, newHeight);
    
    for (std::size_t y = 0; y < srcHeight; ++y) {
        for (std::size_t x = 0; x < srcWidth; ++x) {
            destImage->at(x + posX, y + posY)->copyFrom(srcImage->at(x, y));
        }
    }

}

static CommandRegistrar<PasteCommand> reg_load("paste", "Create a new session and add images to it");