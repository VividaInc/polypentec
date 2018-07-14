// graphics middleware (c) 2018. All rights reserved.

#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "textbox.h"

text_box_t header = {
  .colour = { .r = 0, .g = 0, .b = 0, .a = 0 },
  .draw_rect = { .x = 32, .y = 15, .w = 200, .h = 20 },
};

void CreateTextBox(SDL_Renderer *renderer, text_box_t *box, char *text) {
  SDL_Rect rect;
  SDL_Texture *texture;
  SDL_Surface *surface;
  TTF_Init();
  TTF_Font *font = TTF_OpenFont("C:/Users/Da'Jour Christophe/go/src/dajour.christophe.org/graphic/open-sans.ttf", 24);
  if (font == NULL) {
    fprintf(stderr, "error: font not found\n");
    return;
  }
  SDL_Color color = {box->colour.r, box->colour.g, box->colour.b, box->colour.a};
  surface = TTF_RenderText_Solid(font, text, color);
  texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);
  rect.x = box->draw_rect.x;
  rect.y = box->draw_rect.y;
  rect.w = box->draw_rect.w;
  rect.h = box->draw_rect.h;
  SDL_RenderCopy(renderer, texture, NULL, &rect);
}
