#include "ExitCommand.hpp"
#include "../CommandFactory/CommandRegistrar.hpp"
#include "../../Session/SessionManager.hpp"
#include "../../Session/Session.hpp"

ExitCommand::ExitCommand(Session* currentSession) 
    : Command(currentSession) {
    instant = true;
}

void ExitCommand::execute() {
    std::vector<Session>& sessions = SessionManager::getInstance().getSessions();
    bool isEverythingSaved = true;

    for (int i = 0; i < sessions.size(); i++) {
        std::vector<Session::SessionImage> images = sessions[i].getSessionImages();

        for (int j = 0; j < images.size(); j++)
        {
            if (images[j].status == Session::Status::Modified) {
                std::cout << "You haved unsaved Changes in Session with ID : " << sessions[i].getId() << "\n";
                isEverythingSaved = false;
                break;
            }
        }
        
    }


    if (!isEverythingSaved) {
        std::cout << "Do you want to save the changes (Y/n)? \n>";
        std::string input;
        std::cin >> input;
        if (input == "" && input == "y") {
            // Save changes
        }
    }

    SessionManager::getInstance().setIsRunning(false);
    
}

static CommandRegistrar<ExitCommand> reg_negative("exit", "Exit the application.");