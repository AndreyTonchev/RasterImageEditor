#include "SessionManager.hpp"

SessionManager::SessionManager() 
    : currentSession(nullptr), isRunning(false) {

}

void SessionManager::run() {
    isRunning = true;

    while (isRunning) {
        std::cout << "> ";
        std::string inputLine;
        std::getline(std::cin, inputLine);

        // std::vector<std::string> args = Command::split(inputLine);

        // if (args.empty()) return;

        // std::string cmdName = args[0];
        // args.erase(args.begin());

        // Command* cmd = factory.create(cmdName, currentSession);
        // if (cmd) {
        //     try {
        //         cmd->parse(args);
        //         cmd->validate();
        //         cmd->execute();
        //     } catch (const std::exception& e) {
        //         std::cerr << "Command error: " << e.what() << "\n";
        //     }
        // }

    } 
}