#include <SDL.h>
#include <SDL_vulkan.h>

#include "toy2d/toy2d.hpp"

int main(int argc, const char *argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("sandbox",
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          800, 600,
                                          SDL_WINDOW_SHOWN | SDL_WINDOW_VULKAN);

    if (window == nullptr) {
        SDL_Log("create window failed");
        return -1;
    }

    bool close = false;
    SDL_Event event;

    toy2d::Init();

    while (!close) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                close = true;
            }
        }
    }

    toy2d::Quit();

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
