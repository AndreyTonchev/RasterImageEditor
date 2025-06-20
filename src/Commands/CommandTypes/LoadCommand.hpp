#pragma once

#include <vector>
#include "../Command.hpp"

/**
 * @brief Command that creates a session loads image files into the session.
 * 
 * Stores a list of filenames to load and performs the loading during execution.
 */
class LoadCommand : public Command {
public:
    /**
     * @brief Constructor.
     * 
     * Initializes the command with the current session context.
     * 
     * @param currentSession Pointer to the active session.
     */
    LoadCommand(Session* currentSession);

    /**
     * @brief Parses command-line arguments to extract filenames.
     * 
     * @param args Vector of string arguments representing filenames to load.
     * @throws CommandException If no filenames are provided or session is invalid.
     */
    virtual void parse(const std::vector<std::string>& args) override;

    /**
     * @brief Validates if the command has all necessary data to run.
     * 
     * @throws CommandException If filenames list is empty or session is invalid.
     */
    virtual void validate() const override;

    /**
     * @brief Executes the command by creating a session adnloading all specified image files into the session.
     * 
     * Attempts to create and add images corresponding to each filename.
     */
    virtual void execute() override;

private:
    /**
     * @brief Filenames of the images to load.
     */
    std::vector<std::string> filenames;
};
