#include "HUD.h"
Hud::Hud()
{
 Vector2u resolution;
 resolution.x = VideoMode::getDesktopMode().width;
 resolution.y = VideoMode::getDesktopMode().height;
 // Load the font
 m_Font.loadFromFile("fonts/KOMIKAX_.ttf");
 // when Paused
 m_StartText.setFont(m_Font);
 m_StartText.setCharacterSize(71);
 m_StartText.setFillColor(Color::White);
 m_StartText.setString("Press Enter when ready!");
 // Position the text
 FloatRect textRect = m_StartText.getLocalBounds();
 m_StartText.setOrigin(textRect.left +
 textRect.width / 2.0f,
 textRect.top +
 textRect.height / 2.0f);
 m_StartText.setPosition(
 resolution.x / 2.0f, resolution.y / 2.0f);
 // Time
 m_TimeText.setFont(m_Font);
 m_TimeText.setCharacterSize(54);
 m_TimeText.setFillColor(Color::White);
 m_TimeText.setPosition(resolution.x - 107, 0);
 m_TimeText.setString("------");
 // Level
 m_LevelText.setFont(m_Font);
 m_LevelText.setCharacterSize(54);
 m_LevelText.setFillColor(Color::White);
 m_LevelText.setPosition(18, 0);
 m_LevelText.setString("1");
}
Text Hud::getMessage()
{
 return m_StartText;
}
Text Hud::getLevel()
{
 return m_LevelText;
}
Text Hud::getTime()
{
 return m_TimeText;
}
void Hud::setLevel(String text)
{
 m_LevelText.setString(text);
}
void Hud::setTime(String text)
{
 m_TimeText.setString(text);
}
