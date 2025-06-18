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

        if (cmdName == "help") {
            printHelpMessage();
        } 
        else if (cmdName == "load") {
            addSession(args);
        }
        else if (cmdName == "exit") {
            if (false) {
                // Check if everything is saved
            }
            isRunning = false;
            break;
        } else {

        }


        Command* cmd = CommandFactory::create(cmdName, currentSession);
        if (cmd) {
            try {
                cmd->parse(args);
                cmd->validate();
                currentSession->addCommand(cmd);
            } catch (const std::exception& e) {
                std::cerr << "Command error: " << e.what() << "\n";
                delete cmd;
            }
        }

    } 
}

bool SessionManager::addSession(std::vector<std::string>& images) {
    return true;
}

void SessionManager::printHelpMessage() const {
    std::cout << "help - ";
}