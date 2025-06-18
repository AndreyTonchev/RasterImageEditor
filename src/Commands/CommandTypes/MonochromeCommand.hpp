#pragma once

#include <iostream>

#include "../Command.hpp"

class MonochromeCommand : public Command {
public:
    MonochromeCommand(Session* currentSession);
    virtual void execute() override;
};