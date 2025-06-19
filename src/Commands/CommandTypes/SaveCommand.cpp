#include "SaveCommand.hpp"
#include "../CommandFactory/CommandRegistrar.hpp"
#include "../../utils/Utils.hpp"
#include "../../Images/Image.hpp"
#include "../../Session/Session.hpp"
#include <ctime>

SaveCommand::SaveCommand(Session* currentSession)
    : Command(currentSession) {
    instant = true;
}

void SaveCommand::parse(const std::vector<std::string>& args) {
    if (!args.empty()) {
        throw CommandException("Invalid arguments count passed. Expected ");
    }
}

void SaveCommand::validate() const {
    if (!currentSession) {
        throw CommandException("No active session.");
    }
}

void SaveCommand::execute() {
    std::vector<Session::SessionImage>& images = currentSession->getSessionImages();
    std::vector<Command*>& sessionCommands = currentSession->getSessionCommands();

    std::vector<Session::SessionImage> tempImages;
    for (size_t i = 0; i < images.size(); ++i) {

        Image* tempImage = images[i].image->clone();

        Session::Status newStatus = 
            (images[i].status == Session::Status::PendingLoad) 
            ? Session::Status::PendingLoad 
            : Session::Status::Saved;

        tempImages.emplace_back(tempImage, newStatus);
    }

    for (size_t i = 0; i < sessionCommands.size(); ++i) {
        try {
            sessionCommands[i]->execute();
        } catch (const std::exception& e) {
            std::cerr << "Command failed during save: " << e.what() << std::endl;
        }
    }

    for (size_t i = 0; i < images.size(); ++i) {
        std::string filename = Utils::getFileName(images[i].image->getFilename());
        std::string extension = Utils::getExtension(images[i].image->getFilename());
        std::string timestamp = Utils::getTimestamp();

        std::string newName = filename + "_" + timestamp + "." + extension;

        std::string newFilename = Utils::newFileName(images[i].image->getFilename(), newName);

        try {
            images[i].image->save(newFilename);
        } catch (const std::exception& e) {
            std::cerr << "Failed to save " << newName << ": " << e.what() << std::endl;
        }

        delete images[i].image;
        images[i] = tempImages[i];
        
        std::cout << "Image " << newName << " saved successfully.\n";
    }
}

static CommandRegistrar<SaveCommand> reg_negative("save", "Save all the images with their name + current time");


