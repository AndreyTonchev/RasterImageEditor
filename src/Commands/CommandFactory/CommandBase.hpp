#pragma once

#include "../Command.hpp"


class CommandBase {
public:
    virtual ~CommandBase() = default;

    virtual Command* create(Session* s) const = 0;
};

