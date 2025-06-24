#include "RedoCommand.hpp"
#include "../../Session/Session.hpp"
#include "../CommandFactory/CommandRegistrar.hpp"

RedoCommand::RedoCommand(Session* currentSession) 
    : Command(currentSession) {
    instant = true;
}

void RedoCommand::parse(const std::vector<std::string>& args) {
    if (!currentSession) {
        throw CommandException("No active session.");
    }

    if (!args.empty()) {
        throw CommandException("Invalid arguments count passed. Expected 0");
    }
}

void RedoCommand::execute() {
    std::vector<Command*>& commandQueue = currentSession->getSessionCommands();
    std::vector<Command*>& undoCommandStack = currentSession->getUndoSessionCommands();

    if (undoCommandStack.empty()) {
        std::cout << "No Commands to redo\n"; 
    }

    commandQueue.push_back(undoCommandStack.back());
    undoCommandStack.pop_back();

    std::cout << "Redoed\n";
}

static CommandRegistrar<RedoCommand> reg_load("redo", "redo - Redo the last undoed command");