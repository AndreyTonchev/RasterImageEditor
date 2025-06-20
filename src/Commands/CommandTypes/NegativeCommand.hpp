#pragma once

#include <iostream>

#include "../Command.hpp"

class NegativeCommand : public Command {
public:
    NegativeCommand(Session* currentSession); 
    virtual void parse(const std::vector<std::string>& args) override;
    virtual void execute() override; 
};