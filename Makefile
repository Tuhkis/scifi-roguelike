CC=gcc
CFLAGS=-O3 -pipe -static
OUT=scifi-game
PYTHON=python3
LIB=-lm

COMP=$(CC) $(CFLAGS) -c

all: imgs main.o res.o

imgs: res/*.ppm
	$(PYTHON) scripts/resources.py

main.o: src/main.c
	$(COMP) src/main.c

res.o: src/res.c imgs
	$(COMP) src/res.c

sdl-backend.o: src/sdl-backend.c src/gfx.h src/fps.h
	$(COMP) src/sdl-backend.c

sdl: all sdl-backend.o
	$(CC) *.o -lSDL2 $(LIB) -o $(OUT)
	strip $(OUT)

clean:
	rm res/*.h
	rm *.o
	rm $(OUT)

