#pragma once

#include <iostream>
#include "../Command.hpp"

/**
 * @brief Command to invert the colors of all images in the current session.
 *
 * Applies a pixel-wise negative transformation to each image that is not pending load.
 * This transformation effectively inverts every color channel value.
 */
class NegativeCommand : public Command {
public:
    /**
     * @brief Constructs a NegativeCommand associated with a given session.
     *
     * @param currentSession Pointer to the currently active session.
     */
    NegativeCommand(Session* currentSession); 

    /**
     * @brief Parses the command arguments.
     *
     * @param args Expected to be empty. Throws if session is invalid.
     * @throws CommandException if session is null.
     */
    virtual void parse(const std::vector<std::string>& args) override;

    /**
     * @brief Executes the negative transformation on all loaded images in the session.
     *
     * Skips images with status PendingLoad.
     */
    virtual void execute() override; 
};
