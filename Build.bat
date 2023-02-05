g++ -c -DNQ_Build_Dll src/Utils/*.cpp src/Math/*.cpp src/Core/*.cpp src/Graphic/*.cpp src/Events/*.cpp src/Audio/*.cpp src/Physics/*.cpp src/Network/*.cpp -Wall -O3 -std=c++17 -Isrc -Iexternal
g++ -shared -Wl,--out-implib,bin/libNAQH.a -o bin/NAQH.dll *.o -Lexternal/SDL2 -Lexternal/glad -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_net -lglad -s
del *.o
pause