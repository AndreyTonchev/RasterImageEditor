#pragma once

#include <vector>

#include "../Images/Image.hpp"
#include "../Commands/Command.hpp"

/**
 * @brief Represents an image editing session that manages images and commands.
 * 
 * The Session class stores a collection of images along with their statuses,
 * maintains the list of executed commands, and provides
 * a unique ID for each session instance.
 */
class Session {
public:
    /**
     * @brief Constructs a new Session and assigns a unique ID.
     */
    Session();

    /**
     * @brief Deleted copy constructor to prevent copying of sessions.
     */
    Session(const Session& other) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying of sessions.
     */
    Session& operator=(const Session& other) = delete;

    /**
     * @brief Destructor cleans up any allocated resources.
     */
    ~Session();

    /**
     * @brief Adds a command to the session's command list.
     * 
     * @param cmd Pointer to the Command to add.
     * @return true if the command was added successfully.
     */
    bool addCommand(Command* cmd);

    /**
     * @brief Returns the unique ID of this session.
     * 
     * @return unsigned int Session ID.
     */
    unsigned int getId() const { return id; }

public: 
    /**
     * @brief Enum describing the loading and editing status of an image in the session.
     */
    enum class Status {
        PendingLoad, ///< Image is waiting to be loaded.
        Loaded,      ///< Image has been loaded successfully.
        Modified,    ///< Image has been modified since last save/load.
        Saved        ///< Image has been saved.
    };

    /**
     * @brief Holds an Image pointer and its current status within the session.
     */
    struct SessionImage {
        Image* image;   ///< Pointer to the image.
        Status status;  ///< Current status of the image.

        /**
         * @brief Constructs a SessionImage from an image pointer and status.
         * 
         * @param img Pointer to the Image.
         * @param status Initial status of the image.
         */
        SessionImage(Image* img, Status status);
    };
    
    /**
     * @brief Provides access to the vector of SessionImages.
     * 
     * @return Reference to the vector of SessionImage.
     */
    std::vector<SessionImage>& getSessionImages();

    /**
     * @brief Provides access to the vector of executed commands.
     * 
     * @return Reference to the vector of Command pointers.
     */
    std::vector<Command*>& getSessionCommands();

    /**
     * @brief Provides access to the vector of undoable commands.
     * 
     * @return Reference to the vector of Command pointers that can be undone.
     */
    std::vector<Command*>& getUndoSessionCommands();

private:
    std::vector<SessionImage> images;     ///< List of images and their statuses in the session.
    std::vector<Command*> commands;       ///< Commands that have been executed.
    std::vector<Command*> undoCommands;   ///< Commands that are stored for undo operations.

    unsigned int id;                      ///< Unique session identifier.

private:
    static unsigned int lastId;           ///< Static variable to generate unique IDs.

    /**
     * @brief Generates a new unique ID for each session instance.
     * 
     * @return Unique unsigned int ID.
     */
    static unsigned int generateId();
};
