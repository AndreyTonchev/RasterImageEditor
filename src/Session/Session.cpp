#include "Session.hpp"

std::vector<Image*>& Command::getSessionImages(Session* s) {
    return s->images; // Accessing private member of Session
}