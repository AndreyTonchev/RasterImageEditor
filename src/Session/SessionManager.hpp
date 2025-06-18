#pragma once

#include <iostream>
#include <vector>

#include "Session.hpp"

class SessionManager {
    SessionManager();

    void run();

    bool addSession();
    bool changeSession(unsigned int sessionId);


private:
    std::vector<Session*> sessions;
    Session* currentSession;

    bool isRunning;
};
