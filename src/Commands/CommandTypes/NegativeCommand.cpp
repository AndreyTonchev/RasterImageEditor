#include "NegativeCommand.hpp"
#include "../CommandFactory/CommandRegistrar.hpp"

NegativeCommand::NegativeCommand(Session* currentSession) 
    : Command(currentSession) {

}

void NegativeCommand::execute() {
    std::vector<Image*> images = getSessionImages(currentSession);
    for (int i = 0; i < images.size(); i++) {
        images[i]->negative();
    }
}

void NegativeCommand::validate() const {
    
}

void NegativeCommand::parse(const std::vector<std::string>& args) {

}


static CommandRegistrar<NegativeCommand> reg_negative("negative");