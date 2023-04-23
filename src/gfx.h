#pragma once
#define GFX_H

#include "util.h"

#define W_TITLE "Sci-fi rpg"
#define W_WIDTH 1024
#define W_HEIGHT 512+64

void openDisplay();
void pollEvents();
void clearScreen(u8 r, u8 g, u8 b);
void display();
void cleanGfx();
u8 shouldClose();

