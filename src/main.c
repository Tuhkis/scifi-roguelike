#include <stdio.h>

#include "util.h"
#include "gfx.h"

u8 main(int argc, char* argv[]) {
	openDisplay();
	while (shouldClose() != 1) {
		pollEvents();
		clearScreen(255, 0, 0);
		display();
	}
	cleanGfx();
	return 0;
}

