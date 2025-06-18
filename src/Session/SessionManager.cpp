#include "SessionManager.hpp"
#include "../Commands/CommandFactory/CommandFactory.hpp"

SessionManager::SessionManager() 
    : currentSession(nullptr), isRunning(false) {

}

void SessionManager::run() {
    isRunning = true;

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
                cmd->validate();
                cmd->parse(args);
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

bool SessionManager::addSession() {
    
}

void SessionManager::printHelpMessage() const {
    std::cout << "help - ";
}