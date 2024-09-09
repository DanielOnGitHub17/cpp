#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <memory>
#include "GameScreen.h"
#include "ScreenManagerRemoteControl.h"
#include "SelectScreen.h"
#include "LevelManagement.h"
#include "BitmapStore.h"
#include <iostream>
using namespace sf;
using namespace std;
class ScreenManager : public ScreenManagerRemoteControl {
private:
 map <string, unique_ptr<Screen>> m_Screens;
 LevelManagement m_LevelManagement;
protected:
 string m_CurrentScreen = "Select";
public:
 BitmapStore m_BS;
 ScreenManager(Vector2i res);
 void update(float fps);
 void draw(RenderWindow& window);
 void handleInput(RenderWindow& window);
 /****************************************************
 *****************************************************
 From ScreenManagerRemoteControl interface
Game Programming Design Patterns – Starting the Space Invaders ++ Game
[ 548 ]
 *****************************************************
 *****************************************************/
 void SwitchScreens(string screenToSwitchTo)
 {
 m_CurrentScreen = "" + screenToSwitchTo;
 m_Screens[m_CurrentScreen]->initialise();
 }
 void loadLevelInPlayMode(string screenToLoad)
 {
 m_LevelManagement.getGameObjects().clear();
 m_LevelManagement.
 loadGameObjectsForPlayMode(screenToLoad);
 SwitchScreens("Game");
 }
 vector<GameObject>&
 getGameObjects()
 {
 return m_LevelManagement.getGameObjects();
 }
 GameObjectSharer& shareGameObjectSharer()
 {
 return m_LevelManagement;
 }
};
