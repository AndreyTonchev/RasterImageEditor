#include "AddCommand.hpp"
#include "../CommandFactory/CommandRegistrar.hpp"
#include "../../Session/Session.hpp"
#include "../../utils/Utils.hpp"
#include "../../Images/AllImages.hpp"

AddCommand::AddCommand(Session* currentSession)
    : Command(currentSession) {
    instant = false;
}

void AddCommand::execute() {
    imagePair->status = Session::Status::Loaded;
}

void AddCommand::parse(const std::vector<std::string>& args) {
    if (args.size() != 1) {
        throw CommandException("Invalid arguments count passed. Expected 1");
    }

    std::vector<Session::SessionImage>& images = currentSession->getSessionImages();
    
    Image* image = nullptr;
    try {
        std::string extension = Utils::getExtension(args[0]);

        if (extension == "ppm") {
            image = new PPMImage(args[0]);
        } 
        else if (extension == "pgm") {
            image = new PGMImage(args[0]);
        }
        else if (extension == "pbm") {
            image = new PBMImage(args[0]);
        }
        else {
            throw CommandException("Invalid File Extension");
        }

        images.emplace_back(image, Session::Status::PendingLoad);
        std::cout << "Image " << args[0] << " added successfully\n";

    } catch (const std::exception& e) {
        delete image;
        throw CommandException("Unable to load Image with name " + args[0] + " (" + e.what() +")");
    }
}

static CommandRegistrar<AddCommand> reg_negative("add", "add <filename> - add new Image");