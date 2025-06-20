#pragma once 

#include <iostream>

#include "../Command.hpp"

class RedoCommand : public Command {
public:
    RedoCommand(Session* currentSession);
    virtual void parse(const std::vector<std::string>& args) override;
    virtual void execute() override;
};