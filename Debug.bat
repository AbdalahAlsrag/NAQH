gcc -c src/*.cpp src/Core/*.cpp src/Graphic/*.cpp -Wall -O3 -std=c++17 -Isrc -Iexternal
g++ -o bin/NAQH *.o -mwindows -Lexternal/SDL2 -Lexternal/glad -lmingw32 -lSDL2main -lSDL2 -lSDL2_net -lglad -s
del *.o
start bin/NAQH