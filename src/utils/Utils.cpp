#include "Utils.hpp"
#include <ctime>

namespace Utils {
    std::string getExtension(const std::string& filename) {
        size_t found = filename.find_last_of(".");
        if (found == std::string::npos) {
            return "";
        }
        return filename.substr(found + 1);
    }

    std::string getPath(const std::string& filename) {
        size_t found = filename.find_last_of("/");
        if (found == std::string::npos) {
            return "";
        }
        return filename.substr(0, found + 1);
    }

    std::string getFileName(const std::string& filename) {
        size_t foundDot = filename.find_last_of(".");
        size_t foundSlash = filename.find_last_of("/");

        size_t nameStart = (foundSlash == std::string::npos) ? 0 : foundSlash + 1;

        if (foundDot == std::string::npos || foundDot < nameStart) {
            return filename.substr(nameStart);
        }

        return filename.substr(nameStart, foundDot - nameStart);
    }

    std::string newFileName(const std::string& pathName, const std::string& newName) {
        std::string path = getPath(pathName);
        std::string extension = getExtension(pathName);
        return path + newName;
    }

        std::string pad(int number) {
        return (number < 10 ? "0" : "") + std::to_string(number);
    }

    std::string getTimestamp() {
        time_t now = time(nullptr);
        tm* localTime = localtime(&now);

        std::string timestamp;
        timestamp += std::to_string(localTime->tm_year + 1900);
        timestamp += pad(localTime->tm_mon + 1);
        timestamp += pad(localTime->tm_mday);
        timestamp += pad(localTime->tm_hour);
        timestamp += pad(localTime->tm_min);
        timestamp += pad(localTime->tm_sec);

        return timestamp;
    }
    
}