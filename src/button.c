// graphics middleware (c) 2018. All rights reserved.

#include <stdint.h>
#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "textbox.h"
#include "button.h"

button_t start_button = {
  .colour = { .r = 239, .g = 239, .b = 239, .a = 255 },
  .draw_rect = { .x = 32, .y = 52, .w = 60, .h = 24 },
  .text_box = {
    .colour = { .r = 0, .g = 0, .b = 0, .a = 0 },
    .draw_rect = { .x = 36, .y = 58, .w = 52, .h = 16 },
  },
};

button_t shutdown_button = {
  .colour = { .r = 239, .g = 239, .b = 239, .a = 255 },
  .draw_rect = { .x = 102, .y = 52, .w = 60, .h = 24 },
  .text_box = {
    .colour = { .r = 0, .g = 0, .b = 0, .a = 0 },
    .draw_rect = { .x = 106, .y = 58, .w = 52, .h = 16 },
  },
};

button_t config_button = {
  .colour = { .r = 239, .g = 239, .b = 239, .a = 255 },
  .draw_rect = { .x = 172, .y = 52, .w = 60, .h = 24 },
  .text_box = {
    .colour = { .r = 0, .g = 0, .b = 0, .a = 0 },
    .draw_rect = { .x = 176, .y = 58, .w = 52, .h = 16 },
  },
};

bool CreateButton(SDL_Renderer *renderer, button_t *btn, char *text) {
  SDL_SetRenderDrawColor(renderer, btn->colour.r, btn->colour.g, btn->colour.b, btn->colour.a);
  SDL_RenderFillRect(renderer, &btn->draw_rect);
  CreateTextBox(renderer, &btn->text_box, text);
  if (btn->pressed) {
    btn->pressed = false;
    return true;
  }
  return false;
}

void ButtonAction(SDL_Event *evt, button_t *btn) {
  if (evt->type == SDL_MOUSEBUTTONDOWN) {
    if (evt->button.button == SDL_BUTTON_LEFT && evt->button.x >= btn->draw_rect.x && evt->button.x <= (btn->draw_rect.x + btn->draw_rect.w) && evt->button.y >= btn->draw_rect.y && evt->button.y <= (btn->draw_rect.y + btn->draw_rect.h))
      btn->pressed = true;
  }
}
