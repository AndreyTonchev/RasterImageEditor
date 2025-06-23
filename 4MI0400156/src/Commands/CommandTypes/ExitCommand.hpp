#pragma once

#include <iostream>

#include "../Command.hpp"

/**
 * @brief Command that gracefully terminates the application.
 * 
 * On execution, the command checks all active sessions for unsaved modifications.
 * If any unsaved changes are detected, the user is prompted to save them before exiting.
 */
class ExitCommand : public Command {
public:
    /**
     * @brief Constructs an ExitCommand associated with the current session.
     * 
     * @param currentSession Pointer to the active session.
     */
    ExitCommand(Session* currentSession);

    /**
     * @brief Executes the exit process.
     * 
     * Prompts the user to save any unsaved sessions, then sets the running state of the application to false.
     */
    virtual void execute() override;
};
