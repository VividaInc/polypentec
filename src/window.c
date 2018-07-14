// graphics middleware (c) 2018. All rights reserved.

#include <stdio.h>

#include <SDL2/SDL.h>

#include "window.h"

SDL_Window *CreateWindow(int width, int height) {
  SDL_Window *window;
  if ((window = SDL_CreateWindow("POLYPENTEC v0.1.1a",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    width, height, SDL_WINDOW_OPENGL)) == NULL) {
    printf("could not create window: %s\n", SDL_GetError());
    return NULL;
  }
  return window;
}
