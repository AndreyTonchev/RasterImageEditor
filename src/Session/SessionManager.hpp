#pragma once

#include <iostream>
#include <vector>

#include "Session.hpp"

class SessionManager {
public:   
    static SessionManager& getInstance();
    SessionManager(const SessionManager& other) = delete;
    SessionManager& operator=(const SessionManager& other) = delete;
    SessionManager(const SessionManager&& other) = delete;
    SessionManager& operator=(const SessionManager&& other) = delete;

    void run();

    
    Session* getCurrentSession() const { return currentSession; }
    std::vector<Session>& getSessions();
    
    bool addSession(const Session& newSession);
    bool changeSession(int sessionId);

    inline void setIsRunning(bool value) { isRunning = value; }

private:
    SessionManager();

private:
    std::vector<Session> sessions;
    Session* currentSession; 
    bool isRunning;
};
