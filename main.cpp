#include <iostream>

#include "src/Images/AllImages.hpp"
#include "src/utils/Utils.hpp"
#include "src/Commands/AllComands.hpp"

#include "src/Session/SessionManager.hpp"



int main() {
    
    try { 

        SessionManager::getInstance().run();

    } catch (const std::exception& e) { 
        std::cerr << e.what();
    }

    return 0;
}