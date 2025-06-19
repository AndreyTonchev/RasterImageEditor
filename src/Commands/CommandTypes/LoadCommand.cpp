#include "LoadCommand.hpp"
#include "../CommandFactory/CommandRegistrar.hpp"
#include "../../Session/Session.hpp"
#include "../../Session/SessionManager.hpp"
#include "../../utils/Utils.hpp"
#include "../../Images/AllImages.hpp"

LoadCommand::LoadCommand(Session* currentSession) 
    : Command(currentSession) {
    instant = true;
}

void LoadCommand::execute() {
    Session newSession;
    std::cout << "Session with ID: " << newSession.getId() << " started" << std::endl; 
    std::vector<Image*>& sessionImages = newSession.getSessionImages();

    for (int i = 0; i < filenames.size(); i++) {
        std::cout << "Loading image " << filenames[i] << '\n';
        Image* newImage = nullptr;

        try {
            // TODO - make it with registrar factory
            std::string extension = Utils::getExtension(filenames[i]);

            if (extension == "ppm") {
                newImage = new PPMImage(filenames[i]);
            } 
            else if (extension == "pgm") {
                newImage = new PGMImage(filenames[i]);
            }
            else if (extension == "pbm") {
                newImage = new PBMImage(filenames[i]);
            }
            else {
                throw CommandException("Invalid File Extension");
            }

            std::cout << "Image " << filenames[i] << " loaded successfully\n";
            sessionImages.push_back(newImage);

        } catch (const std::exception& e) {
            std::cout << "Unable to load Image with name" << filenames[i] << " (" << e.what() <<")\n";
            delete newImage;
        }
    }

    if (sessionImages.empty()) {
        throw CommandException("Unable to add Session. Not enough valid image files passed");
    }

    SessionManager::getInstance().addSession(newSession);
    SessionManager::getInstance().changeSession(newSession.getId());
}

void LoadCommand::validate() const {
    if (!(filenames.size() > 0)) {
        throw CommandException("Invalid arguments count passed. Expected >= 1");
    }
}

void LoadCommand::parse(const std::vector<std::string>& args) {
    filenames = args;
}

static CommandRegistrar<LoadCommand> reg_load("load", "Create a new session and add immages to it");