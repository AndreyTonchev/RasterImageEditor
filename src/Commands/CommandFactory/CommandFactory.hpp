#pragma once

#include <string>
#include <vector>

#include "../Command.hpp"
#include "CommandBase.hpp"

class CommandFactory {
public:
    static void registerCommand(const std::string& name, const std::string& description, CommandBase* creator);
    static Command* create(const std::string& name, Session* session);
    static void listCommands();
private:
    struct CommandEntry {
        std::string name;
        std::string description;
        CommandBase* creator;
    }; 

    static std::vector<CommandEntry>& getRegistry();

};

