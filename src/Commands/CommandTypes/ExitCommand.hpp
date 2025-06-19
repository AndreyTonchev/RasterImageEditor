#pragma once

#include <iostream>

#include "../Command.hpp"

class ExitCommand : public Command {
public:
    ExitCommand(Session* currentSession);
    virtual void execute() override;
};