#pragma once
#define PLAYER_H

#include "entity.h"
#include "util.h"

typedef struct {
	 Entity base;
} Player;

Player* newPlayer(i32 x, i32 y);
void playerTick(Player* p, float dt);
void drawPlayer(Player p);

