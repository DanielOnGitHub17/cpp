#include "LevelManagement.h"
#include "PlayModeObjectLoader.h"
#include <iostream>
void LevelManagement::
 loadGameObjectsForPlayMode(string screenToLoad)
{
 m_GameObjects.clear();
 string levelToLoad = ""
 + WORLD_FOLDER + SLASH + screenToLoad;
 PlayModeObjectLoader pmol;
 pmol.loadGameObjectsForPlayMode(
 levelToLoad, m_GameObjects);
 runStartPhase();
}
vector<GameObject>& LevelManagement::getGameObjects()
{
 return m_GameObjects;
}
void LevelManagement::runStartPhase()
{
 auto it = m_GameObjects.begin();
 auto end = m_GameObjects.end();
 for (it;
 it != end;
 ++it)
 {
 (*it).start(this);
 }
 activateAllGameObjects();
}
void LevelManagement::activateAllGameObjects()
{
 auto it = m_GameObjects.begin();
 auto end = m_GameObjects.end();
 for (it;
 it != end;
 ++it)
 {
 (*it).setActive();
 }
}
