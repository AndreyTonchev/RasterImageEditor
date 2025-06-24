#include "UndoCommand.hpp"
#include "../../Session/Session.hpp"
#include "../CommandFactory/CommandRegistrar.hpp"

UndoCommand::UndoCommand(Session* currentSession) 
    : Command(currentSession) {
    instant = true;
}

void UndoCommand::parse(const std::vector<std::string>& args) {
    if (!currentSession) {
        throw CommandException("No active session.");
    }

    if (!args.empty()) {
        throw CommandException("Invalid arguments count passed. Expected 0");
    }
}

void UndoCommand::execute() {
    std::vector<Command*>& commandQueue = currentSession->getSessionCommands();
    std::vector<Command*>& undoCommandStack = currentSession->getUndoSessionCommands();

    if (commandQueue.empty()) {
        std::cout << "No Commands to undo\n"; 
    }

    if (commandQueue.back()->getCanUndo()) {
        undoCommandStack.push_back(commandQueue.back());
        commandQueue.pop_back();

        std::cout << "Undoed\n";
    } else {
        std::cout << "Command can't be undoed\n";
    }

}

static CommandRegistrar<UndoCommand> reg_undo("undo", "udno - Undo the last applied command");