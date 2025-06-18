#pragma once

#include <vector>
#include <string>

#include "../Images/Image.hpp"

class Session;

class Command {
public:
    Command(Session* currentSession);
    
    virtual ~Command() = default; // We dont want to delete the Session when the command dies

    virtual void parse(const std::vector<std::string>& args) = 0;
    virtual void validate() const = 0;
    virtual void execute() = 0;
    
    std::vector<Image*>& getSessionImages(Session* s);

    static std::vector<std::string> split(const std::string& str);
protected:
    Session* currentSession;
};