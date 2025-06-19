#include "SaveAsCommand.hpp"
#include "../CommandFactory/CommandRegistrar.hpp"
#include "../../Session/Session.hpp"
#include "../../utils/Utils.hpp"

SaveAsCommand::SaveAsCommand(Session* currentSession)
    : Command(currentSession) {
    instant = true;
}

void SaveAsCommand::execute() {
    std::vector<Image*>& sessionImages = currentSession->getSessionImages();
    std::vector<Command*>& sessionCommands = currentSession->getSessionCommands();

    std::vector<Image*> tempImages;
    for (size_t i = 0; i < sessionImages.size(); ++i) {
        tempImages.push_back(sessionImages[i]->clone());
    }

    for (size_t i = 0; i < sessionCommands.size(); ++i) {
        try {
            sessionCommands[i]->execute();
        } catch (const std::exception& e) {
            std::cerr << "Command failed during save: " << e.what() << std::endl;
        }
    }

    for (size_t i = 0; i < sessionImages.size(); ++i) {
        std::string newFilename = Utils::newFileName(sessionImages[i]->getFilename(), filenames[i]);
        try {
            sessionImages[i]->save(newFilename);
        } catch (const std::exception& e) {
            std::cerr << "Failed to save " << filenames[i] << ": " << e.what() << std::endl;
        }
        delete sessionImages[i];
        sessionImages[i] = tempImages[i];
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