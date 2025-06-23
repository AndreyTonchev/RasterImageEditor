#include "Command.hpp"
#include "../Session/Session.hpp"

Command::Command(Session* currentSession) 
    : currentSession(currentSession) {
    canUndo = true;
}

std::vector<std::string> Command::split(const std::string& str) {
    std::vector<std::string> args;
    std::string currentArg;

    int count = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] ==' ' || str[i] == '\n') {
            if (!currentArg.empty()) {
                args.push_back(currentArg);
                currentArg.clear();
            }
            continue;
        }
        currentArg += str[i];  
    }

    if (!currentArg.empty()) {
        args.push_back(currentArg);
    }

    return args;

}

void Command::setModifiedStatus() {
    std::vector<Session::SessionImage>& images = currentSession->getSessionImages();

    for (size_t i = 0; i < images.size(); ++i) {
        images[i].status = 
            (images[i].status == Session::Status::PendingLoad) 
            ? Session::Status::PendingLoad 
            : Session::Status::Modified;
    }
}

void Command::setSavedStatus() {
    std::vector<Session::SessionImage>& images = currentSession->getSessionImages();

    for (size_t i = 0; i < images.size(); ++i) {
        images[i].status = 
            (images[i].status == Session::Status::PendingLoad) 
            ? Session::Status::PendingLoad 
            : Session::Status::Saved;
    }
}

void Command::validate() const {
    return;
}

void Command::parse(const std::vector<std::string>& args) {
    if (args.size() > 0) {
        throw CommandException("Invalid elemets count passed. Expected 0");
    }
}

bool Command::isInstant() const {
    return instant;
}

bool Command::getCanUndo() const {
    return canUndo;
}