#pragma once

#include <iostream>

#include "../Command.hpp"
#include "../../Session/Session.hpp"

class AddCommand : public Command {
public:
    AddCommand(Session* currentSession);

    virtual void execute() override;
    virtual void parse(const std::vector<std::string>& args) override;
private:
    Session::SessionImage* sessionImage;
};