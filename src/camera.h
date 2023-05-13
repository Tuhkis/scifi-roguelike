#pragma once
#define CAMERA_H

#include <math.h>

#include "util.h"

typedef struct {
	i32 x, y;
	u8 trauma;
} Camera;

// i32 getCamX(Camera c);
// i32 getCamY(Camera c);

#define CAMX(c) \
	(i32)(c.x - sinf(c.trauma) * c.trauma)

#define CAMY(c) \
	(i32)(c.y - cosf(c.trauma * 2.f) * c.trauma)

