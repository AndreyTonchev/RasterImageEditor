#pragma once

#include <iostream>
#include <vector>

#include "Session.hpp"

class SessionManager {
public:   
    SessionManager();

    void run();

    bool addSession();
    void printHelpMessage() const;
    bool changeSession(unsigned int sessionId);


private:
    std::vector<Session*> sessions;
    Session* currentSession;

    bool isRunning;
};
