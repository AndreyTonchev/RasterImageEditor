#pragma once 

#include <vector>

#include "../Command.hpp"

class LoadCommand : public Command {
public: 
    LoadCommand(Session* currentSession);

    virtual void execute() override;
    virtual void validate() const override;
    virtual void parse(const std::vector<std::string>& args) override;
private:
    std::vector<std::string> filenames;
};