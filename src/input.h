#pragma once
#define INPUT_H

#include "util.h"

typedef struct {
	u8	
	mUp, mDown, mRight, mLeft, // Movement
	sUp, sDown, sRight, sLeft; // Shootin'
} Input;

Input getInput();

