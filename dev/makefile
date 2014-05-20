LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio -lzdll

all: xingu.exe
pugixml.o: source/pugixml/pugixml.cpp
	g++ -c "source/pugixml/pugixml.cpp" -o obj/pugixml.o -std=c++0x
QuadTreeNode.o: source/sfml-tmxloader/QuadTreeNode.cpp
	g++ -c "source/sfml-tmxloader/QuadTreeNode.cpp" -o obj/QuadTreeNode.o -std=c++0x
MapObject.o: source/sfml-tmxloader/MapObject.cpp
	g++ -c "source/sfml-tmxloader/MapObject.cpp" -o obj/MapObject.o -std=c++0x
MapLoaderPublic.o: source/sfml-tmxloader/MapLoaderPublic.cpp
	g++ -c "source/sfml-tmxloader/MapLoaderPublic.cpp" -o obj/MapLoaderPublic.o -std=c++0x
MapLoaderPrivate.o: source/sfml-tmxloader/MapLoaderPrivate.cpp
	g++ -c "source/sfml-tmxloader/MapLoaderPrivate.cpp" -o obj/MapLoaderPrivate.o -std=c++0x
DebugShape.o: source/sfml-tmxloader/DebugShape.cpp
	g++ -c "source/sfml-tmxloader/DebugShape.cpp" -o obj/DebugShape.o -std=c++0x	
MapLayer.o: source/sfml-tmxloader/MapLayer.cpp
	g++ -c "source/sfml-tmxloader/MapLayer.cpp" -o obj/MapLayer.o -std=c++0x	
Display.o: source/Display.cpp
	g++ -c "source/Display.cpp" -o obj/Display.o -std=c++0x
Input.o: source/Input.cpp
	g++ -c "source/Input.cpp" -o obj/Input.o -std=c++0x
MainMenu.o: source/MainMenu.cpp
	g++ -c "source/MainMenu.cpp" -o obj/MainMenu.o -std=c++0x
Scene.o: source/Scene.cpp
	g++ -c "source/Scene.cpp" -o obj/Scene.o -std=c++0x
SceneManager.o: source/SceneManager.cpp
	g++ -c "source/SceneManager.cpp" -o obj/SceneManager.o -std=c++0x
SceneSplash1.o: source/SceneSplash1.cpp
	g++ -c "source/SceneSplash1.cpp" -o obj/SceneSplash1.o -std=c++0x
CollisionManager.o: source/CollisionManager.cpp
	g++ -c "source/CollisionManager.cpp" -o obj/CollisionManager.o -std=c++0x
Bullets.o: source/Bullets.cpp
	g++ -c "source/Bullets.cpp" -o obj/Bullets.o -std=c++0x
Character.o: source/Character.cpp
	g++ -c "source/Character.cpp" -o obj/Character.o -std=c++0x
CharMain.o: source/CharMain.cpp
	g++ -c "source/CharMain.cpp" -o obj/CharMain.o -std=c++0x
Stage1.o: source/Stage1.cpp
	g++ -c "source/Stage1.cpp" -o obj/Stage1.o -std=c++0x
main.o: source/main.cpp
	g++ -c "source/main.cpp" -o obj/main.o -std=c++0x
xingu.exe: Input.o Display.o Scene.o SceneManager.o QuadTreeNode.o MapObject.o MapLoaderPublic.o MapLoaderPrivate.o DebugShape.o MapLayer.o pugixml.o CollisionManager.o Bullets.o Character.o CharMain.o SceneSplash1.o MainMenu.o Stage1.o main.o 
	g++ -o bin/xingu.exe obj/Input.o obj/Display.o obj/Scene.o obj/SceneManager.o obj/QuadTreeNode.o obj/MapObject.o obj/MapLoaderPublic.o obj/MapLoaderPrivate.o obj/DebugShape.o obj/MapLayer.o obj/pugixml.o obj/CollisionManager.o obj/Bullets.o obj/Character.o obj/CharMain.o obj/SceneSplash1.o obj/MainMenu.o obj/Stage1.o obj/main.o $(LIBS) -std=c++0x
