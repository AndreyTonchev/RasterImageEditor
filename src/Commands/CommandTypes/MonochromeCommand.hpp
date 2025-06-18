#pragma once

#include <iostream>

#include "../Command.hpp"

class MonochromeCommand : public Command {
public:
    MonochromeCommand(Session* currentSession);

    virtual void parse(const std::vector<std::string>& args) override; 
    virtual void validate() const override;
    virtual void execute() override;

private:

    
};