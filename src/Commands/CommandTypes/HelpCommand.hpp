#pragma once 

#include <iostream>

#include "../Command.hpp"

class HelpCommand : public Command {
public:
    HelpCommand(Session* currentSession);
    virtual void execute() override;
};