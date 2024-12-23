#include <stdexcept>
#include <iostream>

#include "Core.h"

using namespace std;

int WinMain(int argc, char** args)
{
    GAME_CORE Game;
    try
    {
        Game.Run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}