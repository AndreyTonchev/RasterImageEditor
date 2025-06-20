#pragma once 

#include <iostream>

#include "../Command.hpp"


class UndoCommand : public Command {
public:
    UndoCommand(Session* currentSession);
    virtual void parse(const std::vector<std::string>& args) override;
    virtual void execute() override;
};