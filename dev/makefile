LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio

all: xingu.exe
Display.o: Display.cpp
	g++ -c "Display.cpp" -o Display.o
Input.o: Input.cpp
	g++ -c "Input.cpp" -o Input.o
#SpriteManager.o: SpriteManager.cpp
#	g++ -c "SpriteManager.cpp" -o SpriteManager.o 
MainMenu.o: MainMenu.cpp
	g++ -c "MainMenu.cpp" -o MainMenu.o
Scene.o: Scene.cpp
	g++ -c "Scene.cpp" -o Scene.o
SceneManager.o: SceneManager.cpp
	g++ -c "SceneManager.cpp" -o SceneManager.o
SceneSplash1.o: SceneSplash1.cpp
	g++ -c "SceneSplash1.cpp" -o SceneSplash1.o
Shot.o: Shot.cpp
	g++ -c "Shot.cpp" -o Shot.o	
GamePlay.o: GamePlay.cpp
	g++ -c "GamePlay.cpp" -o GamePlay.o
main.o: main.cpp
	g++ -c "main.cpp" -o main.o
xingu.exe: main.o Input.o Display.o Scene.o SceneManager.o SceneSplash1.o MainMenu.o Shot.o GamePlay.o
	g++ -o xingu.exe main.o Input.o Display.o Scene.o SceneManager.o SceneSplash1.o MainMenu.o Shot.o GamePlay.o $(LIBS)