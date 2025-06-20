#pragma once

#include <iostream>

#include "../Command.hpp"

class PasteCommand : public Command {
public:
    PasteCommand(Session* currentSession);

    virtual void execute() override;
    virtual void parse(const std::vector<std::string>& parse) override;
    virtual void validate() const override;

private:
    Image* srcImage;
    Image* destImage;
    int posX;
    int posY;
};