#pragma once

#include <iostream>

#include "../Command.hpp"

class SaveCommand : public Command {
public:
    SaveCommand(Session* currentSession);

    virtual void execute() override;
    virtual void validate() const override;
    virtual void parse(const std::vector<std::string>& args) override;
};