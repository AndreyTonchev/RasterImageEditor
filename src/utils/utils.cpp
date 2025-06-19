#include "Utils.hpp"

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
    
}