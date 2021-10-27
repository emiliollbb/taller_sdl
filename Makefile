#https://stackoverflow.com/questions/17620884/static-linking-of-sdl2-libraries

#COMPILER_FLAGS specifies the additional compilation options we're using 
COMPILER_FLAGS = -c -Wall -O2

#LINKER_FLAGS specifies the libraries we're linking against 
LINKER_FLAGS = -lstdc++ -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lm

SDL_WIN=/home/emilio/sdl_win/SDL2-2.0.16/x86_64-w64-mingw32

# Include Windows
INCL_WIN=-I/home/emilio/sdl_win/SDL2-2.0.16/x86_64-w64-mingw32/include

# lIB Windows
LIB_WIN=-L/home/emilio/sdl_win/SDL2-2.0.16/x86_64-w64-mingw32/lib -L/home/emilio/sdl_win/SDL2_ttf-2.0.15/x86_64-w64-mingw32/lib -L/home/emilio/sdl_win/SDL2_image-2.0.5/x86_64-w64-mingw32/lib -L/home/emilio/sdl_win/SDL2_mixer-2.0.4/x86_64-w64-mingw32/lib

all: juego

JEngine.o: JEngine.cpp JEngine.hpp
	gcc $(COMPILER_FLAGS) JEngine.cpp -o JEngine.o
	
Juego.o: Juego.cpp Juego.hpp
	gcc $(COMPILER_FLAGS) Juego.cpp -o Juego.o

main.o: main.cpp
	gcc $(COMPILER_FLAGS) main.cpp -o main.o

juego: main.o JEngine.o Juego.o
	gcc $(LINKER_FLAGS) main.o JEngine.o Juego.o -o juego

clean:
	rm -f *.o juego debug	

JEngine.win.o: JEngine.cpp JEngine.hpp
	x86_64-w64-mingw32-gcc $(INCL_WIN) $(LIB_WIN) $(COMPILER_FLAGS) JEngine.cpp -o JEngine.win.o
	
Juego.win.o: Juego.cpp Juego.hpp
	x86_64-w64-mingw32-gcc $(INCL_WIN) $(LIB_WIN) $(COMPILER_FLAGS) Juego.cpp -o Juego.win.o

main.win.o: main.cpp
	x86_64-w64-mingw32-gcc $(INCL_WIN) $(LIB_WIN) $(COMPILER_FLAGS) main.cpp -o main.win.o	

juego.exe: main.win.o JEngine.win.o Juego.win.o
	x86_64-w64-mingw32-g++ -static main.win.o JEngine.win.o Juego.win.o `$(SDL_WIN)/bin/sdl2-config --static-libs` -lSDL2_image -lSDL2_ttf -lSDL2_ttf.dll -lSDL2_mixer -o juego.exe

