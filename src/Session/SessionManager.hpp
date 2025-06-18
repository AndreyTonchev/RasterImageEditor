#pragma once

#include <iostream>
#include <vector>

#include "Session.hpp"

class SessionManager {
    SessionManager();

    void run();

    bool addSession(std::vector<std::string>& images);
    void printHelpMessage() const;
    bool changeSession(unsigned int sessionId);


private:
    std::vector<Session*> sessions;
    Session* currentSession;

    bool isRunning;
};
