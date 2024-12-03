win-args = -Wl,-Bstatic -Iwin-include/ -Lwin-include/ -lraylib -lpthread -Wl,-Bdynamic -lopengl32 -lgdi32 -lwinmm

ubuntu-args = -Wl,-Bstatic -Iinclude/ -Linclude/ -lraylib -Wl,-Bdynamic -lGL -lm -lpthread -lrt -lX11

build-all : ubuntu windows

ubuntu : build/chaos

windows : build/chaos.exe

build/chaos : chaos.c global.h screens/title.h screens/game.h screens/options.h
	gcc chaos.c $(ubuntu-args) -o build/chaos

build/chaos.exe : chaos.c global.h screens/title.h screens/game.h screens/options.h
	x86_64-w64-mingw32-gcc chaos.c $(win-args) -o build/chaos.exe