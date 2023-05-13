CC=gcc
CFLAGS=-O3 -pipe
OUT=scifi-game
PYTHON=python3
LIB=-lm

COMP=$(CC) $(CFLAGS) -c

all: imgs main.o camera.o tilemap.o player.o bullet.o

imgs: res/*.ppm
	$(PYTHON) scripts/resources.py

main.o: src/main.c
	$(COMP) src/main.c

tilemap.o: src/tilemap.c src/tilemap.h
	$(COMP) src/tilemap.c

player.o: src/player.c src/player.h
	$(COMP) src/player.c

bullet.o: src/bullet.c src/bullet.h
	$(COMP) src/bullet.c

camera.o: src/camera.c src/camera.h
	$(COMP) src/bullet.c

sdl-backend.o: src/sdl-backend.c src/gfx.h src/fps.h src/input.h
	$(COMP) src/sdl-backend.c

sdl: all sdl-backend.o
	$(CC) *.o -lSDL2 $(LIB) -o $(OUT)
	strip $(OUT)

clean:
	rm res/*.h
	rm *.o
	rm $(OUT)

