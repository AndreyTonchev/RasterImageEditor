#pragma once

#include <vector>

#include "../Images/Image.hpp"

class Session;

class Command {
public:
    std::vector<Image*>& getSessionImages(Session& s);
};