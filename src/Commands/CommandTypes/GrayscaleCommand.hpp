#pragma once

#include <iostream>

#include "../Command.hpp"

class GrayscaleCommand : public Command {
public:
    GrayscaleCommand(Session* currentSession);
    virtual void execute() override; 
};