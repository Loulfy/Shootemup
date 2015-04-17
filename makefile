

DEFAULT_SRC = src/Model.cpp src/View.cpp src/Level.cpp src/Bullet.cpp src/Entity.cpp src/Ship.cpp src/Frame.cpp src/AssetManager.cpp src/SFMLView.cpp src/SFMLFrame.cpp src/CSLView.cpp src/CSLFrame.cpp
MAIN_SRC = src/Main.cpp
TEST_SRC = src/TestsUnitaires.cpp

default:
	g++ $(DEFAULT_SRC) $(MAIN_SRC) -o shmup -I./src/include -std=c++11 -Wall -lsfml-graphics -lsfml-window -lsfml-system
	
test:
	g++ $(DEFAULT_SRC) $(TEST_SRC) -o TU_shmup -I./src/include -std=c++11 -Wall -lsfml-graphics -lsfml-window -lsfml-system -lboost_unit_test_framework


clean:
	rm -rf *~ */*~ */*/*~ 
