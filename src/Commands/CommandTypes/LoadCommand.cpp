#include "LoadCommand.hpp"
#include "../CommandFactory/CommandRegistrar.hpp"
#include "../../Session/Session.hpp"
#include "../../Session/SessionManager.hpp"
#include "../../utils/Utils.hpp"
#include "../../Images/AllImages.hpp"
#include "../../Images/ImageFactory/ImageFactory.hpp"
#include <iostream>

LoadCommand::LoadCommand(Session* currentSession) 
    : Command(currentSession) {
    instant = true;
}

void LoadCommand::execute() {
    Session* newSession = nullptr;

    try {
        newSession = new Session();

    } catch(const std::exception& e) {   
        delete[] newSession;
        throw CommandException("Unable to load new Session");
    }
    
    std::cout << "==Session with ID: " << newSession->getId() << " started==" << std::endl; 
    std::vector<Session::SessionImage>& images = newSession->getSessionImages();

    for (int i = 0; i < filenames.size(); i++) {
        std::cout << "Loading image " << filenames[i] << '\n';
        Image* newImage = nullptr;

        try {
            std::string extension = Utils::getExtension(filenames[i]);
            
            newImage = ImageFactory::create(extension, filenames[i]);

            if (!newImage){
                throw CommandException("Invalid File Extension");
            }

            std::cout << "Image " << filenames[i] << " loaded successfully\n";
            images.emplace_back(newImage, Session::Status::Loaded);

        } catch (const std::exception& e) {
            std::cout << "Unable to load Image with name " << filenames[i] << " (" << e.what() <<")\n";
            delete newImage;
        }
    }

    if (images.empty()) {
        throw CommandException("Unable to add Session. Not enough valid image files passed");
    }

    SessionManager::getInstance().addSession(newSession);
    SessionManager::getInstance().changeSession(newSession->getId());
}

void LoadCommand::validate() const {
    if (!(filenames.size() > 0)) {
        throw CommandException("Invalid arguments count passed. Expected >= 1");
    }
}

void LoadCommand::parse(const std::vector<std::string>& args) {
    filenames = args;
}

static CommandRegistrar<LoadCommand> reg_load("load", "Create a new session and add images to it");