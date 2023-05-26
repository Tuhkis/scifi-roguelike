#pragma once
#define BULLET_H

#include "util.h"
#include "camera.h"
#include "tilemap.h"

#define BULLET_SPEED 450.f
typedef struct {
	i32 x,  y;
	float vx, vy;
} Bullet;

Bullet* newBullet(i32 x, i32 y, i16 dirX, i16 dirY);
void tickBullet(Bullet* b, float dt, Tilemap tiles);
void drawBullet(Bullet* b, Camera cam);

