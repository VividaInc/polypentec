// graphics middleware (c) 2018. All rights reserved.

#include <stdio.h>

#include <SDL2/SDL.h>

#include "render.h"

SDL_Renderer *CreateRenderer(SDL_Window *window) {
  SDL_Renderer *renderer;
  if ((renderer = SDL_CreateRenderer(window, -1, 0)) == NULL) {
    printf("could not create renderer: %s\n", SDL_GetError());
    return NULL;
  }
  return renderer;
}
