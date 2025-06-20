#pragma once

#include <iostream>

#include "../Command.hpp"

/**
 * @brief Command to convert all images in the current session to grayscale.
 * 
 * This command removes color information from images,
 * converting them to shades of gray.
 */
class GrayscaleCommand : public Command {
public:
    /**
     * @brief Constructs the GrayscaleCommand with the current session.
     * 
     * @param currentSession Pointer to the active session.
     */
    GrayscaleCommand(Session* currentSession);

    /**
     * @brief Parses the command arguments.
     * 
     * Ensures the session is valid and sets the session's modified status.
     * 
     * @param parse Vector of strings containing command arguments.
     * @throws CommandException if there is no active session.
     */
    virtual void parse(const std::vector<std::string>& parse) override;

    /**
     * @brief Executes the command, applying grayscale conversion to all loaded images.
     */
    virtual void execute() override;
};
