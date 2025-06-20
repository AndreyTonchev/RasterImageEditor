#pragma once 

#include <iostream>

#include "../Command.hpp"

/**
 * @brief Command to undo the last executed operation in the current session.
 * 
 * This command reverts the most recent command that supports undo.
 */
class UndoCommand : public Command {
public:
    /**
     * @brief Constructs an UndoCommand associated with the given session.
     * 
     * @param currentSession Pointer to the active Session object.
     */
    UndoCommand(Session* currentSession);

    /**
     * @brief Parses arguments specific to the UndoCommand.
     * 
     * For undo, this typically does nothing but allows consistent interface.
     * 
     * @param args The list of string arguments.
     */
    virtual void parse(const std::vector<std::string>& args) override;

    /**
     * @brief Executes the undo operation.
     * 
     * This pops the last command from the session's history and undoes it,
     * if possible.
     */
    virtual void execute() override;
};
