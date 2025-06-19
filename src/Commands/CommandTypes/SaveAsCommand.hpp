#pragma once

#include <iostream>

#include "../Command.hpp"

class SaveAsCommand : public Command {
public:
    SaveAsCommand(Session* currentSession);

    virtual void execute() override;
    virtual void validate() const override;
    virtual void parse(const std::vector<std::string>& args) override;
private:
    std::vector<std::string> filenames;

    void swapImages(std::vector<Image*>& newImages);
};