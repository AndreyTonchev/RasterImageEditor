#pragma once 

#include <iostream>

#include "../Command.hpp"

/**
 * @brief Command to display help information listing all available commands.
 * 
 * This command calls the CommandFactory to list all registered commands
 * with their descriptions.
 */
class HelpCommand : public Command {
public:
    /**
     * @brief Constructs the HelpCommand with a reference to the current session.
     * 
     * @param currentSession Pointer to the active session.
     */
    HelpCommand(Session* currentSession);

    /**
     * @brief Executes the help command, printing all available commands.
     */
    virtual void execute() override;
};
