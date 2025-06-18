#include "MonochromeCommand.hpp"
#include "../CommandFactory/CommandRegistrar.hpp"

MonochromeCommand::MonochromeCommand(Session* currentSession) 
    : Command(currentSession) {

}

void MonochromeCommand::execute() {
    std::vector<Image*> images = getSessionImages(currentSession);
    for (int i = 0; i < images.size(); i++) {
        images[i]->monochrome();
    }
}

void MonochromeCommand::validate() const {
    
}

void MonochromeCommand::parse(const std::vector<std::string>& args) {

}

static CommandRegistrar<MonochromeCommand> reg_monochrome("monochrome");