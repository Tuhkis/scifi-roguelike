#pragma once
#define INPUT_H

#include "util.h"

typedef struct {
	u8	
	mUp, mDown, mRight, mLeft;
} Input;

Input getInput();

