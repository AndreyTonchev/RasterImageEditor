#pragma once

#include "../Command.hpp"

/**
 * @brief Abstract base class for command creation.
 * 
 * Every command that can be registered and created via the factory must inherit from this.
 */
class CommandBase {
public:
    /// Virtual destructor for safe polymorphic destruction.
    virtual ~CommandBase() = default;

    /**
     * @brief Creates a new instance of a command associated with the given session.
     * 
     * @param s Pointer to the active session.
     * @return Pointer to the created Command object.
     */
    virtual Command* create(Session* s) const = 0;
};
