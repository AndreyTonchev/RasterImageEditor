#pragma once

#include <iostream>
#include "../Command.hpp"

/**
 * @brief Command that saves all images in the session to disk with timestamped filenames.
 * 
 * The command re-executes all session commands and saves the final image state 
 * under a new filename that includes the current timestamp.
 */
class SaveCommand : public Command {
public:
    /**
     * @brief Constructs a SaveCommand for the given session.
     * 
     * @param currentSession Pointer to the active Session object.
     */
    SaveCommand(Session* currentSession);

    /**
     * @brief Parses command arguments.
     * 
     * Validates that no extra arguments are passed and sets session status to Saved.
     * 
     * @param args List of string arguments. Should be empty.
     * @throws CommandException if the argument count is not zero or session is invalid.
     */
    virtual void parse(const std::vector<std::string>& args) override;

    /**
     * @brief Executes the save operation.
     * 
     * Re-applies all commands in the session, then saves each image to a new file.
     * The filename is derived from the original name plus a timestamp.
     * 
     * On failure to save an image, logs an error message to stderr.
     */
    virtual void execute() override;
};
