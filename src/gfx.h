#pragma once
#define GFX_H

#include "util.h"

#define W_TITLE "Sci-fi roguelike"
#define W_WIDTH 1024
#define W_HEIGHT 512+128

#define TEXURES_LEN 16
#define PIX_SIZE 4

void openDisplay();
void pollEvents();
void clearScreen(u8 r, u8 g, u8 b);
void display();
void cleanGfx();
void drawRect(i32 x, i32 y, u16 w, u16 h, u8 r, u8 g, u8 b);
void loadTextureToIndex(u8 w, u8 h, const u8 data[], u8 index);
void drawTexture(i32 x, i32 y, u8 w, u8 h, u8 index, u8 sw, u8 sh, u8 hf, u8 vf, u8 flip);
u8 shouldClose();

