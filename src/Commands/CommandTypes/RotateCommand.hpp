#pragma once

#include <iostream>

#include "../Command.hpp"

class RotateCommand : public Command {
public:
    RotateCommand(Session* currentSession);

    virtual void execute() override;
    virtual void validate() const override;
    virtual void parse(const std::vector<std::string>& args) override;
private:
    std::string direction;
};