#pragma once
#define ENTITY_H

#include "../cPhyc/cPhyc.h"

#include "entity-id.h"

typedef struct {
	Rect rect;
	ENTITY_ID id;
} Entity;

