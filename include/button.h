#ifndef BUTTON_H
#define BUTTON_H

#include <stdbool.h>

typedef struct {
  SDL_Rect draw_rect;
  text_box_t text_box;
  struct {
    Uint8 r, g, b, a;
  } colour;
  bool pressed;
} button_t;

button_t start_button;
button_t shutdown_button;
button_t config_button;

bool CreateButton(SDL_Renderer *renderer, button_t *btn, char *text);
void ButtonAction(SDL_Event *evt, button_t *btn);

#endif /* BUTTON_H */
