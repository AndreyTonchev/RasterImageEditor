#pragma once

#include <string>

namespace Utils {
    std::string getExtension(const std::string& filename);
    std::string getPath(const std::string& filename);
    std::string getFileName(const std::string& filename);
    std::string newFileName(const std::string& pathName, const std::string& newName);
}