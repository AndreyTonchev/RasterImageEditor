#pragma once

#include <string>
#include <vector>

#include "../Command.hpp"
#include "CommandBase.hpp"

/**
 * @brief Factory class for registering and creating commands.
 * 
 * Commands are registered by name and description using a CommandBase creator.
 * The factory allows dynamic creation and listing of all available commands.
 */
class CommandFactory {
public:
    /**
     * @brief Registers a command in the factory.
     * 
     * @param name The name of the command (used for parsing and invocation).
     * @param description A short description of what the command does.
     * @param creator Pointer to a CommandBase that can instantiate the command.
     */
    static void registerCommand(const std::string& name, const std::string& description, CommandBase* creator);

    /**
     * @brief Creates a command instance from its name.
     * 
     * @param name The name of the command to create.
     * @param session The session to bind to the command.
     * @return A pointer to a newly created Command instance.
     * @throws std::runtime_error if the command name is not found.
     */
    static Command* create(const std::string& name, Session* session);

    /**
     * @brief Lists all registered commands and their descriptions.
     */
    static void listCommands();

private:
    /// Structure representing a registered command entry.
    struct CommandEntry {
        std::string name;
        std::string description;
        CommandBase* creator;
    };

    /**
     * @brief Returns a reference to the internal registry of commands.
     * 
     * @return Reference to the static registry vector.
     */
    static std::vector<CommandEntry>& getRegistry();
};
