#pragma once

#include <vector>
#include <string>

#include "../Images/Image.hpp"

class Session;

class Command {
public:
    Command(Session* currentSession);
    
    virtual ~Command() = default; // We dont want to delete the Session when the command dies

    virtual void parse(const std::vector<std::string>& args);
    virtual void validate() const;
    virtual void execute() = 0;

    bool isInstant() const;
    bool getCanUndo() const;
    
    void setModifiedStatus();
    void setSavedStatus();
public:
    static std::vector<std::string> split(const std::string& str);

protected:
    bool instant;
    bool canUndo;
    Session* currentSession;
};



class CommandException : public std::exception {
protected:
    std::string message;

public:
    CommandException(const std::string& msg) 
        : message("Command error : " + msg) {

    }
    const char* what() const noexcept override { return message.c_str(); }
};