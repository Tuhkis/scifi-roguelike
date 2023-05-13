#pragma once
#define PLAYER_H

#include "entity.h"
#include "util.h"
#include "tilemap.h"
#include "bullet.h"
#include "camera.h"

typedef struct {
	 Entity base;
	 float  animTimer;
	 u8     vf, hf, flip;
} Player;

Player* newPlayer(i32 x, i32 y);
void playerTick(Player* p, float dt, Tilemap tiles, Bullet** bullets);
void drawPlayer(Player* p, Camera cam);

