#pragma once

#include <iostream>
#include "../Command.hpp"

/**
 * @brief Command to paste one image onto another at a specified position.
 *
 * This command overlays the source image onto the destination image.
 * If needed, the destination image is resized to fit the source image.
 */
class PasteCommand : public Command {
public:
    /**
     * @brief Constructs a PasteCommand for the given session.
     *
     * Sets the command as non-instant (i.e., it supports undo/redo).
     *
     * @param currentSession Pointer to the current active Session.
     */
    PasteCommand(Session* currentSession);

    /**
     * @brief Parses the command arguments.
     *
     * @param args A vector of strings: {srcFilename, destFilename, posX, posY}
     * @throws CommandException if argument count is invalid or session is null.
     */
    virtual void parse(const std::vector<std::string>& args) override;

    /**
     * @brief Validates the parsed arguments.
     *
     * Currently a no-op; intended for future checks.
     */
    virtual void validate() const override;

    /**
     * @brief Executes the paste operation.
     *
     * Pastes the source image onto the destination image at (posX, posY),
     * resizing the destination if necessary.
     */
    virtual void execute() override;

private:
    /// Pointer to the source image to paste from.
    Image* srcImage;

    /// Pointer to the destination image to paste into.
    Image* destImage;

    /// X-coordinate for the top-left paste position.
    int posX;

    /// Y-coordinate for the top-left paste position.
    int posY;
};
