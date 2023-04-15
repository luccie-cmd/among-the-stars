all:
	g++ -Iinclude -Llib src/*.cpp -o bin/main.exe -lSDL2 -lSDL2main -lSDL2_image -lmingw32