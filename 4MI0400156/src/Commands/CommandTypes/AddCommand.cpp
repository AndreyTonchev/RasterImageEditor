#include "AddCommand.hpp"
#include "../CommandFactory/CommandRegistrar.hpp"
#include "../../Images/ImageFactory/ImageRegistrar.hpp"
#include "../../Session/Session.hpp"
#include "../../utils/Utils.hpp"
#include "../../Images/AllImages.hpp"

AddCommand::AddCommand(Session* currentSession)
    : Command(currentSession) {
    instant = false;
    canUndo = false;
}

void AddCommand::execute() {
    sessionImage->status = Session::Status::Loaded;
}

void AddCommand::parse(const std::vector<std::string>& args) {
    if (!currentSession) {
        throw CommandException("No active session.");
    }

    if (args.size() != 1) {
        throw CommandException("Invalid arguments count passed. Expected 1");
    }

    std::vector<Session::SessionImage>& images = currentSession->getSessionImages();
    
    Image* image = nullptr;
    try {
        std::string extension = Utils::getExtension(args[0]);

            image = ImageFactory::create(extension, args[0]);

            if (!image){
                throw CommandException("Invalid File Extension");
            }

        images.emplace_back(image, Session::Status::PendingLoad);
        sessionImage = &images[images.size() - 1];
        std::cout << "Image " << args[0] << " added successfully\n";

    } catch (const std::exception& e) {
        delete image;
        throw CommandException("Unable to load Image with name " + args[0] + " (" + e.what() +")");
    }
}

static CommandRegistrar<AddCommand> reg_negative("add", "add <filename> - add new Image");