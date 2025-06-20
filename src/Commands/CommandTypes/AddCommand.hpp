#pragma once

#include <iostream>

#include "../Command.hpp"
#include "../../Session/Session.hpp"

/**
 * @brief Command to add a new image to the current session.
 * 
 * This command loads an image file from disk and adds it to the session in a `PendingLoad` state.
 * Once executed, the image status is updated to `Loaded`.
 * 
 * The image is created using the appropriate Image subclass based on the file extension.
 */
class AddCommand : public Command {
public:
    /**
     * @brief Constructs an AddCommand with a pointer to the current session.
     * 
     * @param currentSession Pointer to the session where the image will be added.
     */
    AddCommand(Session* currentSession);

    /**
     * @brief Executes the command, marking the added image as loaded.
     * 
     * This sets the image's status to `Session::Status::Loaded`.
     */
    virtual void execute() override;

    /**
     * @brief Parses the image filename and creates the corresponding image object.
     * 
     * @param args A single-element vector containing the filename.
     * @throws CommandException if no session is active, the argument count is incorrect,
     *         or the image cannot be created or loaded.
     */
    virtual void parse(const std::vector<std::string>& args) override;

private:
    /// Pointer to the newly added session image object.
    Session::SessionImage* sessionImage;
};
