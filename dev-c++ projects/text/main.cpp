#include <sstream>
#include <SFML/Graphics.hpp>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace sf;

int main() {
	VideoMode vid(300, 100);
	RenderWindow window(vid, "Dodge", Style::None);
	std::stringstream strSc;
	strSc << "Daniel is a good boy";
	Text Verse;
	Font font;
	font.loadFromFile("../Vs projects/fonts/KOMIKAP_.ttf");
	Verse.setFont(font);
	Verse.setCharacterSize(20);

	// Choose a color
	Verse.setFillColor(Color::Red);
	Verse.setPosition(0, 0);
	Verse.setString(strSc.str());
	Color color(0, 250, 0, 255);
	while (true){
		window.clear(Color::Transparent);
		window.draw(Verse);
		window.display();
	}
}
