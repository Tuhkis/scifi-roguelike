#include "player.h"

#include <stdlib.h>
#include <math.h>

#include "entity-id.h"
#include "gfx.h"
#include "input.h"
#include "tilemap.h"
#include "bullet.h"

#define P_SPEED 250

u8 bi = 0;
void shoot(Bullet** b, Player* p) {
	b[bi] = newBullet(p->base.rect.x, p->base.rect.y, 1, 0);
	++b;
	if (bi > 64)
		b = 0;
	// newBullet(i32 x, i32 y, i16 dirX, i16 dirY)
}

Player* newPlayer(i32 x, i32 y) {
	Player* p    = malloc(sizeof(Player));
	p->base.id   = ENT_PLAYER;
	p->base.rect = (Rect) {x, y, 57, 57};
	p->flip = 0;
	p->hf = 0;
	p->vf = 0;
	p->animTimer = 0;
	return p;
}

void playerTick(Player* p, float dt, Tilemap tiles, Bullet** bullets) {
	// Movement code
	i8 dx, dy = 0;
	Input i = getInput();
	dx      = i.mRight - i.mLeft;
	dy      = i.mDown  - i.mUp;
	
	moveAndCollide(
		&p->base.rect, tiles, TILES_LEN, 
		dx * P_SPEED * dt, dy * P_SPEED * dt);
	// Anim code
	p->animTimer += dt * 1.9f;
	if (abs( dx + dy ) > 0) {
		p->vf = (u8)(p->animTimer) % 2;
	}
	if        (dy > 0)
		p->hf = 0;
	else if   (dy < 0)
		p->hf = 2;
	if        (dx < 0) {
		p->hf = 1;
		p->flip = 1;
	} else if (dx > 0) {
		p->hf = 1;
		p->flip = 0;
	}

	// Shooting code
	if (i.sRight)
		shoot(bullets, p);
}

void drawPlayer(Player* p) {
	drawTexture(
		p->base.rect.x, p->base.rect.y,
		p->base.rect.w, p->base.rect.h,
		2, 16, 16, p->vf, p->hf, p->flip
	);
}

