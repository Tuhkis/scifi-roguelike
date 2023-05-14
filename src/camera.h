#pragma once
#define CAMERA_H

#include <math.h>

#include "util.h"

typedef struct {
	i32 x, y;
	u8 trauma;
} Camera;

static float aSin[255] = {0};
// static float aCos[255] = {0};

#define CAMX(c) \
	(c.x - (aSin[c.trauma] * c.trauma))

#define CAMY(c) \
	(c.y - (aSin[c.trauma + 90] * c.trauma))

