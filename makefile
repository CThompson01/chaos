win-args = -Wl,-Bstatic -Iinclude/win/ -Linclude/win/ -lraylib -lpthread -Wl,-Bdynamic -lopengl32 -lgdi32 -lwinmm

ubuntu-args = -Wl,-Bstatic -Iinclude/linux/ -Linclude/linux/ -lraylib -Wl,-Bdynamic -lGL -lm -lpthread -lrt -lX11

build-all : ubuntu windows

ubuntu : build/chaos

windows : build/chaos.exe

build/chaos : src/chaos.c src/global.h src/screens/title.h src/screens/game.h src/screens/options.h
	gcc src/chaos.c $(ubuntu-args) -o build/chaos

build/chaos.exe : src/chaos.c src/global.h src/screens/title.h src/screens/game.h src/screens/options.h src/resources/
	x86_64-w64-mingw32-gcc src/chaos.c $(win-args) -o build/chaos.exe
	cp -r src/resources build/resources