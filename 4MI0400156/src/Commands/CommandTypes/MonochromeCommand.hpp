#pragma once

#include <iostream>
#include "../Command.hpp"

/**
 * @brief Command to convert all images in the session to monochrome (pure black and white).
 *
 * This command applies a binary threshold to each pixel, turning it either full black or white.
 * Only operates on images that are already loaded.
 */
class MonochromeCommand : public Command {
public:
    /**
     * @brief Constructs a MonochromeCommand associated with a given session.
     *
     * @param currentSession Pointer to the currently active session.
     */
    MonochromeCommand(Session* currentSession);

    /**
     * @brief Parses the command arguments.
     *
     * @param parse Expected to be empty. Throws if session is invalid.
     * @throws CommandException if session is null.
     */
    virtual void parse(const std::vector<std::string>& parse) override;

    /**
     * @brief Executes the monochrome transformation on all loaded images in the session.
     *
     * Skips images with status PendingLoad.
     */
    virtual void execute() override;
};
