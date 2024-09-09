#include <SFML/Graphics.hpp>
using namespace sf;
int main(){
	VideoMode vm(1366, 768);
	RenderWindow window(vm, "Moving Ball", Style::Fullscreen);
	Texture ballTexture;
	ballTexture.loadFromFile("images/ball.png");
	Sprite ball;
	ball.setTexture(ballTexture);
	ball.setPosition(683, 384);
	ball.setOrigin(50,50);
	Clock clock; Event event;
	float speed;
	while(window.isOpen()){
 		Time dt = clock.restart();
 		speed = dt.asSeconds()*200;
		while (window.pollEvent(event)){
			if (event.type == Event::Closed) window.close();
 		}
		if (Keyboard::isKeyPressed(Keyboard::Escape)){
			window.close();
 		}
		if (Keyboard::isKeyPressed(Keyboard::Left)){
			ball.setPosition(ball.getPosition().x-speed, ball.getPosition().y);
			ball.rotate(-0.182);
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)){
			ball.setPosition(ball.getPosition().x+speed, ball.getPosition().y);
			ball.rotate(0.182);
		}
		if(ball.getPosition().x<-20){
			ball.setPosition(1390, 384);
		}
		if(ball.getPosition().x>1390){
			ball.setPosition(-20, 384);
		}
		
		window.clear();
		window.draw(ball);
		window.display();
	}
}
