#pragma once

#include <string>

#include "CommandBase.hpp"
#include "CommandFactory.hpp"


template <typename T>
class CommandRegistrar : public CommandBase {
public:
    CommandRegistrar(const std::string& name, const std::string& description);
    Command* create(Session* s) const;

};

template <typename T>
CommandRegistrar<T>::CommandRegistrar(const std::string& name, const std::string& description) {
    CommandFactory::registerCommand(name, description, this);
}

template <typename T>
Command* CommandRegistrar<T>::create(Session* s) const {
    return new T(s);
}