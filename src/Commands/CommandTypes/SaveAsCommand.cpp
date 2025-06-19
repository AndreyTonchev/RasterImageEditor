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

    for (size_t i = 0; i < images.size(); ++i) {
        std::string newFilename = Utils::newFileName(images[i].image->getFilename(), filenames[i]);
        try {
            images[i].image->save(newFilename);
        } catch (const std::exception& e) {
            std::cerr << "Failed to save " << filenames[i] << ": " << e.what() << std::endl;
        }
        delete images[i].image;
        images[i] = tempImages[i];
        
        std::cout << "Image " << filenames[i] << " saved successfully.\n";
    }

}
    
void SaveAsCommand::validate() const {
    int filesAmmount = currentSession->getSessionImages().size();
    if (filenames.size() != filesAmmount) {
        throw CommandException("Invalid arguments count passed. Expected " + filesAmmount);
    }
}

void SaveAsCommand::parse(const std::vector<std::string>& args) {
    filenames = args;
}

static CommandRegistrar<SaveAsCommand> reg_negative("saveas", "Save all the images as the specified names");