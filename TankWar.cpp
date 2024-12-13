#include <stdexcept>
#include <iostream>
#include "Graphics.h"

using namespace std;

int WinMain(int argc, char** args)
{
    SDL_ADAPTER adapter;
    try
    {
        adapter.run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}