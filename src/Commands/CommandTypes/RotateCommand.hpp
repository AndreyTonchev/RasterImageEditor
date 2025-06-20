#pragma once

#include <iostream>
#include "../Command.hpp"

/**
 * @brief Command to rotate all loaded images in the session either left or right.
 * 
 * The rotation is 90 degrees in the specified direction. Only images with
 * a loaded, saved or modified status will be rotated.
 */
class RotateCommand : public Command {
public:
    /**
     * @brief Constructs a RotateCommand for the given session.
     * 
     * @param currentSession Pointer to the active Session object.
     */
    RotateCommand(Session* currentSession);

    /**
     * @brief Executes the rotation on all eligible session images.
     * 
     * Rotates each image 90 degrees either left (clockwise) or right (counter-clockwise).
     * 
     * @throws CommandException if the direction is invalid.
     */
    virtual void execute() override;

    /**
     * @brief Validates the direction argument.
     * 
     * Ensures that the direction is either "left" or "right".
     * 
     * @throws CommandException if the direction is invalid.
     */
    virtual void validate() const override;

    /**
     * @brief Parses the rotation direction.
     * 
     * @param args A single-element vector containing the rotation direction.
     * @throws CommandException if no session exists or argument count is invalid.
     */
    virtual void parse(const std::vector<std::string>& args) override;

private:
    /// Direction of rotation: either "left" or "right".
    std::string direction;
};
