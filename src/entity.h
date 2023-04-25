#pragma once
#define ENTITY_H

#include "tilemap.h"
#include "entity-id.h"
#include "gfx.h"

typedef struct {
	Rect rect;
	ENTITY_ID id;
} Entity;

#define M_DRAW_ENTITY(e, r, g, b) \
	drawRect(e.rect.x, e.rect.y, e.rect.w, e.rect.h, r, g, b)

