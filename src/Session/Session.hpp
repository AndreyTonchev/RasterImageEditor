#pragma once

#include <vector>

#include "../Images/Image.hpp"
#include "../Commands/Command.hpp"


class Session {
public:
    Session();
    Session(const Session& other) = delete;
    Session& operator=(const Session& other) = delete;
    ~Session();

    bool addCommand(Command* cmd);
    unsigned int getId() const { return id; }


public: 
    enum class Status {
        PendingLoad,
        Loaded,
        Modified,
        Saved
    };

    struct SessionImage {
        Image* image;
        Status status;
        
        SessionImage(Image* img, Status status);
    };
    
    std::vector<SessionImage>& getSessionImages();
    std::vector<Command*>& getSessionCommands();
    std::vector<Command*>& getUndoSessionCommands();

private:
    std::vector<SessionImage> images;
    std::vector<Command*> commands;
    std::vector<Command*> undoCommands;

    unsigned int id;

private:
    static unsigned int lastId;
    static unsigned int generateId();
};