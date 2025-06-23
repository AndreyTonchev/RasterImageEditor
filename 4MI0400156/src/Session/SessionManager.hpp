#pragma once

#include <iostream>
#include <vector>

#include "Session.hpp"

/**
 * @brief Singleton manager class that controls multiple sessions.
 * 
 * Manages creation, switching, and tracking of active editing sessions.
 */
class SessionManager {
public:
    /**
     * @brief Gets the singleton instance of SessionManager.
     * 
     * @return Reference to the SessionManager instance.
     */
    static SessionManager& getInstance();
    
    // Delete copy and move semantics for singleton
    SessionManager(const SessionManager& other) = delete;
    SessionManager& operator=(const SessionManager& other) = delete;
    SessionManager(const SessionManager&& other) = delete;
    SessionManager& operator=(const SessionManager&& other) = delete;

    /**
     * @brief Destroys the SessionManager and cleans up sessions.
     */
    ~SessionManager();

    /**
     * @brief Main run loop or processing logic for sessions.
     * 
     * This function can be used to process session tasks or maintain state.
     */
    void run();

    /**
     * @brief Gets the currently active session.
     * 
     * @return Pointer to the current Session.
     */
    Session* getCurrentSession() const { return currentSession; }

    /**
     * @brief Gets the vector of all managed sessions.
     * 
     * @return Reference to the vector containing pointers to Session objects.
     */
    std::vector<Session*>& getSessions();

    /**
     * @brief Adds a new session to the manager.
     * 
     * @param newSession Pointer to the Session to add.
     * @return true if successfully added, false otherwise.
     */
    bool addSession(Session* newSession);

    /**
     * @brief Changes the currently active session by ID.
     * 
     * @param sessionId The ID of the session to switch to.
     * @return true if the session switch was successful, false if sessionId not found.
     */
    bool changeSession(int sessionId);

    /**
     * @brief Sets the running state of the manager.
     * 
     * @param value Boolean indicating whether the manager is running.
     */
    inline void setIsRunning(bool value) { isRunning = value; }

private:
    /**
     * @brief Private constructor for singleton pattern.
     */
    SessionManager();

private:
    std::vector<Session*> sessions;  ///< Container holding all active sessions
    Session* currentSession;          ///< Pointer to the current active session
    bool isRunning;                  ///< Indicates if the manager is currently running
};