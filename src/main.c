// polypentec graphics middleware (c) 2018. All rights reserved.

#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_Main.h>

#include "init.h"
#include "window.h"
#include "render.h"
#include "textbox.h"
#include "button.h"

enum {
  STATE_IN_MENU,
  STATE_IN_GAME,
} state = 0;

int running = 1;

int main(int argc, char *argv[]) {
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Event event;
  InitApplication();
  window = CreateWindow(480, 320);
  renderer = CreateRenderer(window);
  SDL_SetRenderDrawColor(renderer, 245, 245, 245, 255);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
  while (running) {
    if (SDL_PollEvent(&event)) {
      if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE) {
        running = 0;
        break;
      } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
        running = 0;
        break;
      } else if (event.type == SDL_QUIT) {
        running = 0;
        break;
      }
      ButtonAction(&event, &start_button);
      ButtonAction(&event, &shutdown_button);
      ButtonAction(&event, &config_button);
    }
    if (state == STATE_IN_MENU) {
    }
    CreateTextBox(renderer, &header, "Polypentec Control Panel v0.1.1a");
    if (CreateButton(renderer, &start_button, "Start")) {
      system("pptc -start");
      state = STATE_IN_GAME;
    } else if(state == STATE_IN_GAME) {
      // DO SOMETHING ELSE LATER ON ...
    }
    if (CreateButton(renderer, &shutdown_button, "Shutdown")) {
      system("pptc -stop");
      state = STATE_IN_GAME;
    } else if(state == STATE_IN_GAME) {
      // DO SOMETHING ELSE LATER ON ...
    }
    if (CreateButton(renderer, &config_button, "Config")) {
      printf("%s\n", "automated configuration is not supported. conduct a manual configuration.");
      state = STATE_IN_GAME;
    } else if(state == STATE_IN_GAME) {
      // DO SOMETHING ELSE LATER ON ...
    }
    SDL_RenderPresent(renderer);
  }
  SDL_Delay(1000);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
