#pragma once 

#include <iostream>

#include "../Command.hpp"

class ListCommand : public Command {
public:
    ListCommand(Session* currentSession);
    virtual void parse(const std::vector<std::string>& args) override;
    virtual void execute() override;
};