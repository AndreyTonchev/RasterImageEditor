#include "ListCommand.hpp"
#include "../../Session/Session.hpp"
#include "../CommandFactory/CommandRegistrar.hpp"
#include "../../Images/ImageFactory/ImageRegistrar.hpp"
#include "../../Images/ImageFactory/ImageFactory.hpp"
#include "../../utils/Utils.hpp"

ListCommand::ListCommand(Session* currentSession) 
    : Command(currentSession) {
    instant = true;
}

void ListCommand::parse(const std::vector<std::string>& args) {
    if (!currentSession) {
        throw CommandException("No active session.");
    }

    if (!args.empty()) {
        throw CommandException("Invalid arguments count passed. Expected 0");
    }
}

void ListCommand::execute() {
    std::vector<Session::SessionImage>& images = currentSession->getSessionImages();
    int sessionId = currentSession->getId();

    std::cout << "Files in session with ID " << sessionId << ":\n";
    for (size_t i = 0; i < images.size(); i++)
    {
        std::string filename = Utils::getFileName(images[i].image->getFilename());
        std::string extension = Utils::getExtension(images[i].image->getFilename());
        std::string description = ImageFactory::getImageDescription(extension);

        std::cout << filename << " - " << description << '\n';
    }
    
}

static CommandRegistrar<ListCommand> reg_list("list", "List info about the current session");
