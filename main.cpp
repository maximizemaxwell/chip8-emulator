//
// Created by max on 7/26/24.
//
#define SDL_MAIN_HANDLED

#include <iostream>
#include <SDL.h>
using namespace std;

const int windowheight = 600;
const int windowwidth = 800;

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    return 1;
    cout << "Initialization failed" << endl;
    }

   SDL_Window* window = SDL_CreateWindow(
   "Chip-8 Emulator",
   SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
   windowwidth, windowheight,
   SDL_WINDOW_SHOWN
   );

   if (window == NULL) {
       SDL_Quit();
       return 2;
   }

   SDL_Renderer* r = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

   bool quit = false;
   SDL_Event event;

   while (!quit) {
       while (SDL_PollEvent(&event) {
           if (event.type == SDL_QUIT) {
               quit = true;
           }
       }
       SDL_SetRenderDrawColor(r, 255, 255, 255, SDL_ALPHA_OPAQUE);
       SDL_RenderClear(r);
       SDL_Delay(100);
   }
}
