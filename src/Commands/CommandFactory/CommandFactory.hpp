#pragma once

#include <string>
#include <vector>

#include "../Command.hpp"
#include "CommandBase.hpp"

class CommandFactory {
public:
    static void registerCommand(const std::string& name, CommandBase* creator);
    static Command* create(const std::string& name, Session* session);

private:
    struct CommandEntry {
        std::string name;
        CommandBase* creator;
    }; 

    static std::vector<CommandEntry>& getRegistry();

};

