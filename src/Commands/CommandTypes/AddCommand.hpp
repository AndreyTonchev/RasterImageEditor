#pragma once

#include <iostream>

#include "../Command.hpp"

class AddCommand : public Command {
public:
    AddCommand(Session* currentSession);

    virtual void execute() override;
    virtual void validate() const override;
    virtual void parse(const std::vector<std::string>& args) override;
private:
    Image* image;
};