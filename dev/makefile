LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio

all: xingu.exe
pugixml.o: pugixml/pugixml.cpp
	g++ -c "pugixml/pugixml.cpp" -o pugixml.o -std=c++0x
QuadTreeNode.o: sfml-tmxloader/QuadTreeNode.cpp
	g++ -c "sfml-tmxloader/QuadTreeNode.cpp" -o QuadTreeNode.o -std=c++0x
MapObject.o: sfml-tmxloader/MapObject.cpp
	g++ -c "sfml-tmxloader/MapObject.cpp" -o MapObject.o -std=c++0x
MapLoaderPublic.o: sfml-tmxloader/MapLoaderPublic.cpp
	g++ -c "sfml-tmxloader/MapLoaderPublic.cpp" -o MapLoaderPublic.o -std=c++0x
MapLoaderPrivate.o: sfml-tmxloader/MapLoaderPrivate.cpp
	g++ -c "sfml-tmxloader/MapLoaderPrivate.cpp" -o MapLoaderPrivate.o -std=c++0x
Display.o: Display.cpp
	g++ -c "Display.cpp" -o Display.o -std=c++0x
Input.o: Input.cpp
	g++ -c "Input.cpp" -o Input.o -std=c++0x
#SpriteManager.o: SpriteManager.cpp
#	g++ -c "SpriteManager.cpp" -o SpriteManager.o 
MainMenu.o: MainMenu.cpp
	g++ -c "MainMenu.cpp" -o MainMenu.o -std=c++0x
Scene.o: Scene.cpp
	g++ -c "Scene.cpp" -o Scene.o -std=c++0x
SceneManager.o: SceneManager.cpp
	g++ -c "SceneManager.cpp" -o SceneManager.o -std=c++0x
SceneSplash1.o: SceneSplash1.cpp
	g++ -c "SceneSplash1.cpp" -o SceneSplash1.o -std=c++0x
Shot.o: Shot.cpp
	g++ -c "Shot.cpp" -o Shot.o	
GamePlay.o: GamePlay.cpp 
	g++ -c "GamePlay.cpp" -o GamePlay.o -std=c++0x
main.o: main.cpp
	g++ -c "main.cpp" -o main.o -std=c++0x
xingu.exe: main.o QuadTreeNode.o MapObject.o MapLoaderPublic.o MapLoaderPrivate.o Input.o Display.o Scene.o SceneManager.o SceneSplash1.o MainMenu.o Shot.o GamePlay.o pugixml.o
	g++ -o xingu.exe main.o Input.o Display.o Scene.o SceneManager.o SceneSplash1.o MainMenu.o Shot.o GamePlay.o pugixml.o QuadTreeNode.o MapObject.o MapLoaderPublic.o MapLoaderPrivate.o $(LIBS) -std=c++0x
