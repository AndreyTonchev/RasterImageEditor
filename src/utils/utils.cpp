#include "Utils.hpp"

namespace Utils {
    std::string getExtension(const std::string& filename) {
        size_t found = filename.find_last_of(".");
        if (found == std::string::npos) {
            return "";
        }
        return filename.substr(found + 1);
    }
}