#include "ExitCommand.hpp"
#include "../CommandFactory/CommandRegistrar.hpp"
#include "../../Session/SessionManager.hpp"
#include "../../Session/Session.hpp"

ExitCommand::ExitCommand(Session* currentSession) 
    : Command(currentSession) {
    instant = true;
}

void ExitCommand::execute() {
    std::vector<Session*>& sessions = SessionManager::getInstance().getSessions();
    std::vector<Session*> unsavedSessions;

    for (int i = 0; i < sessions.size(); i++) {
        std::vector<Session::SessionImage> images = sessions[i]->getSessionImages();

        for (int j = 0; j < images.size(); j++)
        {
            if (images[j].status == Session::Status::Modified) {
                std::cout << "You haved unsaved Changes in Session with ID : " << sessions[i]->getId() << "\n";
                unsavedSessions.push_back(sessions[i]);
                break;
            }
        }
        
    }\


    if (!unsavedSessions.empty()) {
        std::cout << "Do you want to save the changes (Y/n)? \n>";
        std::string input = "";
        std::cin >> input;
        if (input == "" || input == "y") {
            for (int i = 0; i < unsavedSessions.size(); i++) {
                Command* cmd = CommandFactory::create("save", unsavedSessions[i]);
                if (cmd)
                {
                    cmd->execute();
                    delete cmd;
                }
                else {
                    std::cout << "Unable to save images in Session with ID : " << unsavedSessions[i]->getId() << "\n";
                }
                
            }
            
        }
    }

    SessionManager::getInstance().setIsRunning(false);
    
}

static CommandRegistrar<ExitCommand> reg_negative("exit", "Exit the application.");