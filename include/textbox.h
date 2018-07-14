#ifndef TEXTBOX_H
#define TEXTBOX_H

typedef struct {
  SDL_Rect draw_rect;
  struct {
    Uint8 r, g, b, a;
  } colour;
} text_box_t;

text_box_t header;

void CreateTextBox(SDL_Renderer *renderer, text_box_t *box, char *text);

#endif /* TEXTBOX_H */
