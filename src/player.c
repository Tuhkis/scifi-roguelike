#include "player.h"

#include <stdlib.h>

#include "entity-id.h"

Player* newPlayer(i32 x, i32 y) {
	Player* p    = malloc(sizeof(Player));
	p->base.id   = ENT_PLAYER;
	p->base.rect = (Rect) {x, y, 64, 64};
	return p;
}

