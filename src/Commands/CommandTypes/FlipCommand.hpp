#pragma once

#include <iostream>

#include "../Command.hpp"

/**
 * @brief Command to flip all images in the current session horizontally or vertically.
 * 
 * This command mirrors each loaded image in the session across the specified axis:
 * - "left" or "right" → Horizontal flip (mirror on vertical axis)
 * - "top" or "bottom" → Vertical flip (mirror on horizontal axis)
 */
class FlipCommand : public Command {
public:
    /**
     * @brief Constructs a FlipCommand with a pointer to the current session.
     * 
     * @param currentSession Pointer to the active session.
     */
    FlipCommand(Session* currentSession);

    /**
     * @brief Executes the flip operation on all eligible images in the session.
     */
    virtual void execute() override;

    /**
     * @brief Validates the flip direction argument.
     * 
     * @throws CommandException if direction is not one of: "left", "right", "top", "bottom".
     */
    virtual void validate() const override;

    /**
     * @brief Parses the direction argument and sets image status to modified.
     * 
     * @param args A single-element vector containing the flip direction.
     * @throws CommandException if no session is active or arguments are invalid.
     */
    virtual void parse(const std::vector<std::string>& args) override;

private:
    /// The direction to flip images: "left", "right", "top", or "bottom".
    std::string direction;
};
