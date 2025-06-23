#pragma once 

#include <iostream>

#include "../Command.hpp"

/**
 * @brief Command to list information about all images in the current session.
 * 
 * This command outputs filenames and their descriptions for all images
 * currently loaded in the session.
 */
class ListCommand : public Command {
public:
    /**
     * @brief Constructs the ListCommand with a reference to the current session.
     * 
     * @param currentSession Pointer to the active session.
     */
    ListCommand(Session* currentSession);

    /**
     * @brief Parses command arguments.
     * 
     * Expects no arguments; throws if any are provided or session is invalid.
     * 
     * @param args Vector of argument strings (expected empty).
     * @throws CommandException If arguments are present or session is null.
     */
    virtual void parse(const std::vector<std::string>& args) override;

    /**
     * @brief Executes the command to print info about all images in the session.
     */
    virtual void execute() override;
};
