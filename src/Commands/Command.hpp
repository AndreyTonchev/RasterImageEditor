#pragma once

#include <vector>
#include <string>

#include "../Images/Image.hpp"

class Session;

/**
 * @brief Abstract base class representing a command in a session.
 * 
 * Commands can be parsed, validated, and executed. Each command can optionally
 * be undoable and/or instant (not stored in the command history).
 */
class Command {
public:
    /**
     * @brief Constructs a Command with a pointer to the current session.
     * 
     * @param currentSession Pointer to the current active Session.
     */
    Command(Session* currentSession);
    
    /**
     * @brief Virtual destructor (defaulted). Does not delete the session.
     */
    virtual ~Command() = default;

    /**
     * @brief Parses arguments required to configure the command.
     * 
     * @param args Vector of string arguments.
     */
    virtual void parse(const std::vector<std::string>& args);

    /**
     * @brief Validates the command's internal state after parsing.
     * 
     * Throws a CommandException if validation fails.
     */
    virtual void validate() const;

    /**
     * @brief Executes the command. Must be implemented by all derived classes.
     */
    virtual void execute() = 0;

    /**
     * @brief Checks whether this command is instant.
     * 
     * Instant commands are executed immediately and not stored in the command stack.
     * 
     * @return true if the command is instant, false otherwise.
     */
    bool isInstant() const;

    /**
     * @brief Checks whether this command can be undone.
     * 
     * @return true if the command supports undo, false otherwise.
     */
    bool getCanUndo() const;

    /**
     * @brief Sets the session image(s) status to modified.
     */
    void setModifiedStatus();

    /**
     * @brief Sets the session image(s) status to saved.
     */
    void setSavedStatus();

    /**
     * @brief Utility function to split a string into tokens by whitespace.
     * 
     * @param str The string to split.
     * @return A vector of tokens (substrings).
     */
    static std::vector<std::string> split(const std::string& str);

protected:
    bool instant;              ///< Whether the command is instant.
    bool canUndo;              ///< Whether the command supports undo.
    Session* currentSession;   ///< Pointer to the associated session.
};


/**
 * @brief Exception class used to represent errors during command execution.
 */
class CommandException : public std::exception {
protected:
    std::string message; ///< Error message associated with the exception.

public:
    /**
     * @brief Constructs a CommandException with a given message.
     * 
     * @param msg The error message describing the problem.
     */
    CommandException(const std::string& msg) 
        : message("Command error : " + msg) {}

    /**
     * @brief Returns the error message.
     * 
     * @return Pointer to a C-string containing the error message.
     */
    const char* what() const noexcept override { return message.c_str(); }
};
