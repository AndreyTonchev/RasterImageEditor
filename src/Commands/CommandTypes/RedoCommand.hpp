#pragma once 

#include <iostream>
#include "../Command.hpp"

/**
 * @brief Command to redo the last undone operation in the current session.
 * 
 * This command re-applies the last command that was previously undone,
 * assuming one exists in the session's undo stack.
 */
class RedoCommand : public Command {
public:
    /**
     * @brief Constructs a RedoCommand for the given session.
     * 
     * Marks the command as `instant`, meaning it executes immediately.
     * 
     * @param currentSession Pointer to the active Session.
     */
    RedoCommand(Session* currentSession);

    /**
     * @brief Parses the command arguments.
     * 
     * @param args Expected to be empty. Throws if any arguments are passed.
     * @throws CommandException if arguments are invalid or session is null.
     */
    virtual void parse(const std::vector<std::string>& args) override;

    /**
     * @brief Executes the redo operation.
     * 
     * Moves the most recently undone command from the undo stack
     * back to the active command queue and marks it as redone.
     * 
     * @throws CommandException if the undo stack is empty.
     */
    virtual void execute() override;
};
