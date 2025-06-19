#include "SaveAsCommand.hpp"
#include "../CommandFactory/CommandRegistrar.hpp"
#include "../../Session/Session.hpp"
#include "../../utils/Utils.hpp"

SaveAsCommand::SaveAsCommand(Session* currentSession)
    : Command(currentSession) {
    instant = true;
}

void SaveAsCommand::execute() {
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

    std::string timestamp = Utils::getTimestamp();

    for (size_t i = 0; i < images.size(); ++i) {
        std::string newFilename;
        
        if (i < filenames.size()) {
            newFilename = Utils::newFileName(images[i].image->getFilename(), filenames[i]);
        } else {
            std::string filename = Utils::getFileName(images[i].image->getFilename());
            std::string extension = Utils::getExtension(images[i].image->getFilename());
            std::string newName = filename + "_" + timestamp + "." + extension;

            newFilename = Utils::newFileName(images[i].image->getFilename(), newName);
        }

        try {
            images[i].image->save(newFilename);
        } catch (const std::exception& e) {
            std::cerr << "Failed to save " << newFilename << ": " << e.what() << std::endl;
        }
        delete images[i].image;
        images[i] = tempImages[i];
        
        std::cout << "Image " << newFilename << " saved successfully.\n";
    }

}
    
void SaveAsCommand::validate() const {
    int filesAmount = currentSession->getSessionImages().size();
    if (filenames.size() > filesAmount) {
        throw CommandException("Invalid arguments count passed. Max Elements Expected " + filesAmount);
    }
}

void SaveAsCommand::parse(const std::vector<std::string>& args) {
    filenames = args;
}

static CommandRegistrar<SaveAsCommand> reg_negative("saveas", "Save all the images as the specified names");