#include "HelpCommand.hpp"
#include "../CommandFactory/CommandRegistrar.hpp"

HelpCommand::HelpCommand(Session* session) 
    : Command(currentSession) {
    instant = true;
}

void HelpCommand::execute() {
    CommandFactory::listCommands();
}

static CommandRegistrar<HelpCommand> reg_help("help", "List all the available commands.");