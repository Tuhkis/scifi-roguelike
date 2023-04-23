CC=gcc
CFLAGS=-O3 -pipe -static
OUT=scifi-game

COMP=$(CC) $(CFLAGS) -c

all: main.o

main.o: src/main.c
	$(COMP) src/main.c

sdl-backend.o: src/sdl-backend.c src/gfx.h src/fps.h
	$(COMP) src/sdl-backend.c

sdl: all sdl-backend.o
	$(CC) *.o -lSDL2 -o $(OUT)
	strip $(OUT)

clean:
	rm *.o
	rm $(OUT)

