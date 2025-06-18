#pragma once

#include <iostream>

#include "../Command.hpp"

class GrayscaleCommand : public Command {
public:
    virtual void parse(const std::vector<std::string>& args) override; 
    virtual void validate() const override;
    virtual void execute() override;

    virtual Command* clone() const override;

private:

    
};