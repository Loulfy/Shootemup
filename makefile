default:
	g++ src/*.cpp -o shmup -I./src/include -std=c++11 -Wall -lsfml-graphics -lsfml-window -lsfml-system
