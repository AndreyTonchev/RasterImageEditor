#include "SessionManager.hpp"
#include "../Commands/CommandFactory/CommandFactory.hpp"

SessionManager& SessionManager::getInstance() {
    static SessionManager instance;
    return instance;
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

    } 
}

bool SessionManager::addSession(const Session& newSession) {
    sessions.push_back(newSession);
    return true;
}

bool SessionManager::changeSession(int sessionId) {
    for (int i = 0; i < sessions.size(); i++) {
        if (sessions[i].getId() == sessionId) {
            currentSession = &sessions[i];
            return true;
        }
    }
    return false;
}
