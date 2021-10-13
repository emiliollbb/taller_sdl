#COMPILER_FLAGS specifies the additional compilation options we're using 
COMPILER_FLAGS = -c -Wall -O2

#LINKER_FLAGS specifies the libraries we're linking against 
LINKER_FLAGS = -lstdc++ -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lm

all: juego

JEngine.o: JEngine.cpp
	gcc $(COMPILER_FLAGS) JEngine.cpp -o JEngine.o

main.o: main.cpp
	gcc $(COMPILER_FLAGS) main.cpp -o main.o

juego: main.o JEngine.o
	gcc $(LINKER_FLAGS) main.o JEngine.o -o juego

clean:
	rm -f *.o juego debug	
