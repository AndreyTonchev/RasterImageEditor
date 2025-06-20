#pragma once

#include <string>

#include "CommandBase.hpp"
#include "CommandFactory.hpp"

/**
 * @brief Template helper for registering commands with the factory.
 * 
 * Each specific command class `T` must inherit from Command and provide a constructor
 * taking `Session*` as its only argument.
 * 
 * Registration is performed automatically via static initialization.
 * 
 * @tparam T The command type to register.
 */
template <typename T>
class CommandRegistrar : public CommandBase {
public:
    /**
     * @brief Constructs and registers a command with the factory.
     * 
     * @param name The command name.
     * @param description The command description.
     */
    CommandRegistrar(const std::string& name, const std::string& description);

    /**
     * @brief Creates an instance of the command.
     * 
     * @param s Pointer to the current session.
     * @return A pointer to a newly created command instance.
     */
    Command* create(Session* s) const override;
};

template <typename T>
CommandRegistrar<T>::CommandRegistrar(const std::string& name, const std::string& description) {
    CommandFactory::registerCommand(name, description, this);
}

template <typename T>
Command* CommandRegistrar<T>::create(Session* s) const {
    return new T(s);
}
