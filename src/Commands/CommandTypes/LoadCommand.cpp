#include "LoadCommand.hpp"
#include "../CommandFactory/CommandRegistrar.hpp"

LoadCommand::LoadCommand(Session* currentSession) 
    : Command(currentSession) {
    instant = true;
}

void LoadCommand::execute() {
    
}

void LoadCommand::parse(const std::vector<std::string>& args) {
    filenames = args;
}
