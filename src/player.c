#include "player.h"

#include <stdlib.h>
#include "../cPhyc/cPhyc.h"
#include <math.h>

#include "entity-id.h"
#include "gfx.h"
#include "input.h"

#define P_SPEED 250

Player* newPlayer(i32 x, i32 y) {
	Player* p    = malloc(sizeof(Player));
	p->base.id   = ENT_PLAYER;
	p->base.rect = (Rect) {x, y, 64, 64};
	p->hf = 0;
	p->vf = 0;
	p->animTimer = 0;
	return p;
}

void playerTick(Player* p, float dt) {
	// Movement code
	i8 dx, dy = 0;
	Input i    = getInput();
	dx         = i.mRight - i.mLeft;
	dy         = i.mDown  - i.mUp;

	moveAndCollide(
		&p->base.rect, NULL, 0, 
		dx * P_SPEED * dt, dy * P_SPEED * dt);
	// Anim code
	p->animTimer += dt * 1.9f;
	if (abs( dx + dy ) > 0) {
		p->vf = (u8)(p->animTimer) % 2;
	}
}

void drawPlayer(Player* p) {
	drawTexture(
		p->base.rect.x, p->base.rect.y,
		p->base.rect.w, p->base.rect.h,
		2, 16, 16, p->vf, p->hf);
}

