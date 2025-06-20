#include "SessionManager.hpp"
#include "../Commands/CommandFactory/CommandFactory.hpp"

SessionManager& SessionManager::getInstance() {
    static SessionManager instance;
    return instance;
}

SessionManager::~SessionManager() {
    for (int i = 0; i < sessions.size(); i++) {
        delete sessions[i];
    }
    
}

SessionManager::SessionManager() 
    : currentSession(nullptr), isRunning(false) {
}

void SessionManager::run() {
    isRunning = true;
    std::cout << "Raster Image Editor\n" 
              << "Write 'help' to list the commands\n";      

    while (isRunning) {
        std::cout << "> ";
        std::string inputLine;
        std::getline(std::cin, inputLine);

        std::vector<std::string> args = Command::split(inputLine);

        if (args.empty()) {
            continue;
        }

        std::string cmdName = args[0];
        args.erase(args.begin());

        Command* cmd = CommandFactory::create(cmdName, currentSession);
        if (cmd && (currentSession || cmd->isInstant())) {
            try {
                cmd->parse(args);
                cmd->validate();
                if (cmd->isInstant()) {
                    cmd->execute();
                    delete cmd;
                } 
                else {
                    currentSession->addCommand(cmd);
                }
            } catch (const std::exception& e) {
                std::cerr << e.what() << "\n";
                delete cmd;
            }
        }
        else if (!cmd) {
            std::cout << "Command not found! Write 'help' to see the list of available commands\n";
        }
        else {
            std::cout << "You need to load a Session First\n";
        }

    } 
}

bool SessionManager::addSession(Session* newSession) {
    sessions.push_back(newSession);
    return true;
}

std::vector<Session*>& SessionManager::getSessions() {
    return sessions;
}

bool SessionManager::changeSession(int sessionId) {
    for (int i = 0; i < sessions.size(); i++) {
        if (sessions[i]->getId() == sessionId) {
            currentSession = sessions[i];
            return true;
        }
    }
    return false;
}
