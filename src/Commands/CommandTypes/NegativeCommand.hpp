#pragma once

#include <iostream>

#include "../Command.hpp"

class NegativeCommand : public Command {
public:
    NegativeCommand(Session* currentSession); 
    virtual void execute() override; 
};