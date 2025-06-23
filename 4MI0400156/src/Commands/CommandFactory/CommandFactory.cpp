#include "CommandFactory.hpp"


std::vector<CommandFactory::CommandEntry>& CommandFactory::getRegistry() {
    static std::vector<CommandEntry> registry;
    return registry;
}

void CommandFactory::registerCommand(const std::string& name, const std::string& description, CommandBase* creator) {
    getRegistry().push_back({ name, description, creator });
}

Command* CommandFactory::create(const std::string& name, Session* session) {
    std::vector<CommandEntry>& registry = getRegistry();

    for (std::size_t i = 0; i < registry.size(); ++i) {
        const CommandEntry& entry = registry[i];
        if (entry.name == name) {
            return entry.creator->create(session);
        }
    }

    return nullptr;
}

void CommandFactory::listCommands() {
    std::cout << "Image Commands:\n";
    std::vector<CommandEntry>& registry = getRegistry();
    for (size_t i = 0; i < registry.size(); i++) {
        std::cout << " " << registry[i].name << " - " << registry[i].description << '\n';
    }
    
}
