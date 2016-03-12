#To compile in Windows include the -lzdll on LIBS
#To compile in Linux include the -lz on LIBS
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio -lz

all: xingu.exe
obj/Random.o: source/Random.cpp
	g++ -c "source/Random.cpp" -o obj/Random.o -std=c++0x
obj/pugixml.o: source/pugixml/pugixml.cpp
	g++ -c "source/pugixml/pugixml.cpp" -o obj/pugixml.o -std=c++0x
obj/QuadTreeNode.o: source/sfml-tmxloader/QuadTreeNode.cpp
	g++ -c "source/sfml-tmxloader/QuadTreeNode.cpp" -o obj/QuadTreeNode.o -std=c++0x
obj/MapObject.o: source/sfml-tmxloader/MapObject.cpp
	g++ -c "source/sfml-tmxloader/MapObject.cpp" -o obj/MapObject.o -std=c++0x
obj/MapLoaderPublic.o: source/sfml-tmxloader/MapLoaderPublic.cpp
	g++ -c "source/sfml-tmxloader/MapLoaderPublic.cpp" -o obj/MapLoaderPublic.o -std=c++0x
obj/MapLoaderPrivate.o: source/sfml-tmxloader/MapLoaderPrivate.cpp
	g++ -c "source/sfml-tmxloader/MapLoaderPrivate.cpp" -o obj/MapLoaderPrivate.o -std=c++0x
obj/DebugShape.o: source/sfml-tmxloader/DebugShape.cpp
	g++ -c "source/sfml-tmxloader/DebugShape.cpp" -o obj/DebugShape.o -std=c++0x	
obj/MapLayer.o: source/sfml-tmxloader/MapLayer.cpp
	g++ -c "source/sfml-tmxloader/MapLayer.cpp" -o obj/MapLayer.o -std=c++0x	
obj/Display.o: source/Display.cpp
	g++ -c "source/Display.cpp" -o obj/Display.o -std=c++0x
obj/Input.o: source/Input.cpp
	g++ -c "source/Input.cpp" -o obj/Input.o -std=c++0x
obj/Infos.o: source/Infos.cpp
	g++ -c "source/Infos.cpp" -o obj/Infos.o -std=c++0x
obj/MainMenu.o: source/MainMenu.cpp
	g++ -c "source/MainMenu.cpp" -o obj/MainMenu.o -std=c++0x
obj/Scene.o: source/Scene.cpp
	g++ -c "source/Scene.cpp" -o obj/Scene.o -std=c++0x
obj/SceneManager.o: source/SceneManager.cpp
	g++ -c "source/SceneManager.cpp" -o obj/SceneManager.o -std=c++0x
obj/SceneSplash1.o: source/SceneSplash1.cpp
	g++ -c "source/SceneSplash1.cpp" -o obj/SceneSplash1.o -std=c++0x
obj/CollisionObject.o: source/CollisionObject.cpp
	g++ -c "source/CollisionObject.cpp" -o obj/CollisionObject.o -std=c++0x
obj/CollisionManager.o: source/CollisionManager.cpp
	g++ -c "source/CollisionManager.cpp" -o obj/CollisionManager.o -std=c++0x
obj/Bullets.o: source/Bullets.cpp
	g++ -c "source/Bullets.cpp" -o obj/Bullets.o -std=c++0x
obj/Gun.o: source/Gun.cpp
	g++ -c "source/Gun.cpp" -o obj/Gun.o -std=c++0x
obj/GunManager.o: source/GunManager.cpp
	g++ -c "source/GunManager.cpp" -o obj/GunManager.o -std=c++0x
obj/SpriteManager.o: source/SpriteManager.cpp
	g++ -c "source/SpriteManager.cpp" -o obj/SpriteManager.o -std=c++0x
obj/DropItem.o: source/DropItem.cpp
	g++ -c "source/DropItem.cpp" -o obj/DropItem.o -std=c++0x
obj/DropStamina.o: source/DropStamina.cpp
	g++ -c "source/DropStamina.cpp" -o obj/DropStamina.o -std=c++0x
obj/DropHealth.o: source/DropHealth.cpp
	g++ -c "source/DropHealth.cpp" -o obj/DropHealth.o -std=c++0x
obj/DropBullets.o: source/DropBullets.cpp
	g++ -c "source/DropBullets.cpp" -o obj/DropBullets.o -std=c++0x
obj/DropXp.o: source/DropXp.cpp
	g++ -c "source/DropXp.cpp" -o obj/DropXp.o -std=c++0x
obj/DropColt.o: source/DropColt.cpp
	g++ -c "source/DropColt.cpp" -o obj/DropColt.o -std=c++0x
obj/DropLuger.o: source/DropLuger.cpp
	g++ -c "source/DropLuger.cpp" -o obj/DropLuger.o -std=c++0x
obj/DropMauser.o: source/DropMauser.cpp
	g++ -c "source/DropMauser.cpp" -o obj/DropMauser.o -std=c++0x
obj/DropWinchester.o: source/DropWinchester.cpp
	g++ -c "source/DropWinchester.cpp" -o obj/DropWinchester.o -std=c++0x
obj/DropManager.o: source/DropManager.cpp
	g++ -c "source/DropManager.cpp" -o obj/DropManager.o -std=c++0x
obj/Character.o: source/Character.cpp
	g++ -c "source/Character.cpp" -o obj/Character.o -std=c++0x
obj/CharMain.o: source/CharMain.cpp
	g++ -c "source/CharMain.cpp" -o obj/CharMain.o -std=c++0x
obj/CharEnemmy.o: source/CharEnemmy.cpp
	g++ -c "source/CharEnemmy.cpp" -o obj/CharEnemmy.o -std=c++0x
obj/Hud.o: source/Hud.cpp
	g++ -c "source/Hud.cpp" -o obj/Hud.o -std=c++0x
obj/Wave.o: source/Wave.cpp
	g++ -c "source/Wave.cpp" -o obj/Wave.o -std=c++0x
obj/WaveManager.o: source/WaveManager.cpp
	g++ -c "source/WaveManager.cpp" -o obj/WaveManager.o -std=c++0x
obj/LoaderImages.o: source/LoaderImages.cpp
	g++ -c "source/LoaderImages.cpp" -o obj/LoaderImages.o -std=c++0x
obj/SaveGame.o: source/SaveGame.cpp
	g++ -c "source/SaveGame.cpp" -o obj/SaveGame.o -std=c++0x
obj/Tutorial.o: source/Tutorial.cpp
	g++ -c "source/Tutorial.cpp" -o obj/Tutorial.o -std=c++0x
obj/Cutscene1.o: source/Cutscene1.cpp
	g++ -c "source/Cutscene1.cpp" -o obj/Cutscene1.o -std=c++0x
obj/Cutscene2.o: source/Cutscene2.cpp
	g++ -c "source/Cutscene2.cpp" -o obj/Cutscene2.o -std=c++0x
obj/Cutscene3.o: source/Cutscene3.cpp
	g++ -c "source/Cutscene3.cpp" -o obj/Cutscene3.o -std=c++0x
obj/MenuInGame.o: source/MenuInGame.cpp
	g++ -c "source/MenuInGame.cpp" -o obj/MenuInGame.o -std=c++0x
obj/GamePlay.o: source/GamePlay.cpp
	g++ -c "source/GamePlay.cpp" -o obj/GamePlay.o -std=c++0x
obj/Stage1.o: source/Stage1.cpp
	g++ -c "source/Stage1.cpp" -o obj/Stage1.o -std=c++0x
obj/Stage2.o: source/Stage2.cpp
	g++ -c "source/Stage2.cpp" -o obj/Stage2.o -std=c++0x
obj/GamePlayPost.o: source/GamePlayPost.cpp
	g++ -c "source/GamePlayPost.cpp" -o obj/GamePlayPost.o -std=c++0x
obj/GameOver.o: source/GameOver.cpp
	g++ -c "source/GameOver.cpp" -o obj/GameOver.o -std=c++0x
obj/main.o: source/main.cpp
	g++ -c "source/main.cpp" -o obj/main.o -std=c++0x
#For compile to Windows	
#obj/xingu.res: source/xingu.rc
#	windres "source/xingu.rc" -O coff -o obj/xingu.res
#xingu.exe: obj/Random.o obj/Input.o obj/Display.o obj/Scene.o obj/SceneManager.o obj/QuadTreeNode.o obj/MapObject.o obj/MapLoaderPublic.o obj/MapLoaderPrivate.o obj/DebugShape.o obj/MapLayer.o obj/pugixml.o obj/CollisionObject.o obj/CollisionManager.o obj/Bullets.o obj/Gun.o obj/GunManager.o obj/SpriteManager.o obj/DropItem.o obj/DropStamina.o obj/DropHealth.o obj/DropBullets.o obj/DropXp.o obj/DropColt.o obj/DropLuger.o obj/DropMauser.o obj/DropWinchester.o obj/DropManager.o obj/Character.o obj/CharMain.o obj/CharEnemmy.o obj/Hud.o obj/Wave.o obj/WaveManager.o obj/SceneSplash1.o obj/Infos.o obj/MainMenu.o obj/LoaderImages.o obj/SaveGame.o obj/Tutorial.o obj/Cutscene1.o obj/Cutscene2.o obj/Cutscene3.o obj/MenuInGame.o obj/GamePlay.o obj/Stage1.o obj/Stage2.o obj/GamePlayPost.o obj/GameOver.o obj/main.o obj/xingu.res
#	g++ -o bin/xingu.exe obj/Random.o obj/Input.o obj/Display.o obj/Scene.o obj/SceneManager.o obj/QuadTreeNode.o obj/MapObject.o obj/MapLoaderPublic.o obj/MapLoaderPrivate.o obj/DebugShape.o obj/MapLayer.o obj/pugixml.o obj/CollisionObject.o obj/CollisionManager.o obj/Bullets.o obj/Gun.o obj/GunManager.o obj/SpriteManager.o obj/DropItem.o obj/DropStamina.o obj/DropHealth.o obj/DropBullets.o obj/DropXp.o obj/DropColt.o obj/DropLuger.o obj/DropMauser.o obj/DropWinchester.o obj/DropManager.o obj/Character.o obj/CharMain.o obj/CharEnemmy.o obj/Hud.o obj/Wave.o obj/WaveManager.o obj/SceneSplash1.o obj/Infos.o obj/MainMenu.o obj/LoaderImages.o obj/SaveGame.o obj/Tutorial.o obj/Cutscene1.o obj/Cutscene2.o obj/Cutscene3.o obj/MenuInGame.o obj/GamePlay.o obj/Stage1.o obj/Stage2.o obj/GamePlayPost.o obj/GameOver.o obj/main.o obj/xingu.res $(LIBS) -std=c++0x
#For compile to Linux
xingu.exe: obj/Random.o obj/Input.o obj/Display.o obj/Scene.o obj/SceneManager.o obj/QuadTreeNode.o obj/MapObject.o obj/MapLoaderPublic.o obj/MapLoaderPrivate.o obj/DebugShape.o obj/MapLayer.o obj/pugixml.o obj/CollisionObject.o obj/CollisionManager.o obj/Bullets.o obj/Gun.o obj/GunManager.o obj/SpriteManager.o obj/DropItem.o obj/DropStamina.o obj/DropHealth.o obj/DropBullets.o obj/DropXp.o obj/DropColt.o obj/DropLuger.o obj/DropMauser.o obj/DropWinchester.o obj/DropManager.o obj/Character.o obj/CharMain.o obj/CharEnemmy.o obj/Hud.o obj/Wave.o obj/WaveManager.o obj/SceneSplash1.o obj/Infos.o obj/MainMenu.o obj/LoaderImages.o obj/SaveGame.o obj/Tutorial.o obj/Cutscene1.o obj/Cutscene2.o obj/Cutscene3.o obj/MenuInGame.o obj/GamePlay.o obj/Stage1.o obj/Stage2.o obj/GamePlayPost.o obj/GameOver.o obj/main.o
	g++ -o bin/xingu.exe obj/Random.o obj/Input.o obj/Display.o obj/Scene.o obj/SceneManager.o obj/QuadTreeNode.o obj/MapObject.o obj/MapLoaderPublic.o obj/MapLoaderPrivate.o obj/DebugShape.o obj/MapLayer.o obj/pugixml.o obj/CollisionObject.o obj/CollisionManager.o obj/Bullets.o obj/Gun.o obj/GunManager.o obj/SpriteManager.o obj/DropItem.o obj/DropStamina.o obj/DropHealth.o obj/DropBullets.o obj/DropXp.o obj/DropColt.o obj/DropLuger.o obj/DropMauser.o obj/DropWinchester.o obj/DropManager.o obj/Character.o obj/CharMain.o obj/CharEnemmy.o obj/Hud.o obj/Wave.o obj/WaveManager.o obj/SceneSplash1.o obj/Infos.o obj/MainMenu.o obj/LoaderImages.o obj/SaveGame.o obj/Tutorial.o obj/Cutscene1.o obj/Cutscene2.o obj/Cutscene3.o obj/MenuInGame.o obj/GamePlay.o obj/Stage1.o obj/Stage2.o obj/GamePlayPost.o obj/GameOver.o obj/main.o $(LIBS) -std=c++0x
