#pragma once

#include <iostream>

#include "../Command.hpp"

class FlipCommand : public Command {
public:
    FlipCommand(Session* currentSession);

    virtual void execute() override;
    virtual void validate() const override;
    virtual void parse(const std::vector<std::string>& args) override;
private:
    std::string direction;
};
