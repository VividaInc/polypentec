// graphics middleware (c) 2018. All rights reserved.

#include <SDL2/SDL.h>

#include "init.h"

void InitApplication() {
  if ((SDL_Init(SDL_INIT_EVERYTHING)) < -1)
    return;
}
