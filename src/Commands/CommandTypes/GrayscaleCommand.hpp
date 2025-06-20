#pragma once

#include <iostream>

#include "../Command.hpp"

class GrayscaleCommand : public Command {
public:
    GrayscaleCommand(Session* currentSession);
    virtual void execute() override; 
    virtual void parse(const std::vector<std::string>& parse) override;
};