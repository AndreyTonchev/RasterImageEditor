#pragma once

#include <iostream>
#include "../Command.hpp"

/**
 * @brief Command to save each image in the session under a specified filename.
 * 
 * Unlike SaveCommand, this allows the user to provide exact filenames for the images.
 */
class SaveAsCommand : public Command {
public:
    /**
     * @brief Constructs a SaveAsCommand for the given session.
     * 
     * @param currentSession Pointer to the active Session object.
     */
    SaveAsCommand(Session* currentSession);

    /**
     * @brief Executes the save-as operation.
     * 
     * Saves each session image to the corresponding provided filename.
     * 
     * @throws CommandException if saving fails or session is invalid.
     */
    virtual void execute() override;

    /**
     * @brief Validates that the number of filenames matches the number of images.
     * 
     * @throws CommandException if validation fails.
     */
    virtual void validate() const override;

    /**
     * @brief Parses and stores the provided filenames.
     * 
     * @param args List of output filenames, one for each session image.
     * @throws CommandException if no filenames are provided or session is invalid.
     */
    virtual void parse(const std::vector<std::string>& args) override;

private:
    /// Filenames provided for saving each session image.
    std::vector<std::string> filenames;
};
