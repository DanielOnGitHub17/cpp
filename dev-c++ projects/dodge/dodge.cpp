#include <sstream>
#include <SFML/Graphics.hpp>

using namespace sf;
int pos(int gen), rPos[3];
int cPos = 2;
int main() {
	VideoMode vid(1366, 768);
	RenderWindow window(vid, "Dodge", Style::Fullscreen);
	
	// Texture(cat and mice)
	Texture catTex, ratTex;
	catTex.loadFromFile("images/cat.png");
    ratTex.loadFromFile("images/mouse.png");
	
	
	//Sprites (cat and mice)
	Sprite cat;
	cat.setTexture(catTex);
	cat.setPosition(633, 600);
	
	Sprite rat[3];
	for (int i = 0; i<3; i++){
		rat[i].setTexture(ratTex);
		rat[i].setPosition(pos(i*10), i*230);
	}
	// cover two sides with one white
    RectangleShape cover1;
    cover1.setSize(Vector2f(456, 768));
    cover1.setFillColor(Color::Green);
    cover1.setPosition(0, 0);
    
    //white
    RectangleShape cover2;
    cover2.setSize(Vector2f(454, 768));
    cover2.setFillColor(Color::White);
    cover2.setPosition(456, 0);
    
    //green again
    RectangleShape cover3;
    cover3.setSize(Vector2f(456, 768));
    cover3.setFillColor(Color::Green);
    cover3.setPosition(910, 0);
    
    //there's time for everything
    Clock clock;
    
	bool pressable = true, paused = false;
	
	//i "don" hear your scores
	int score = 10, inTime;
	float spd = 100, time = 0.0f;
	Text scTxt, endit;
	
	
	// We need to choose a font
	Font font;
	font.loadFromFile("../Vs projects/fonts/KOMIKAP_.ttf");
 
	// Set the font to our message
	scTxt.setFont(font);

	// Make it really big
	scTxt.setCharacterSize(40);
 
	// Choose a color
	scTxt.setFillColor(Color::Black);
	endit = scTxt;
	scTxt.setPosition(0, 20);

	while (window.isOpen()){
		//fixing the "key" problem
		Event evt;
		while (window.pollEvent(evt)){
			if (evt.type == Event::KeyReleased){
        	    // Listen for key presses again
        		pressable = true;
			}
 		}
 		std::stringstream strSc;
 		strSc << "score: " << score << " Time is: " << inTime;
		scTxt.setString(strSc.str());
		//for exit
		if(Keyboard::isKeyPressed(Keyboard::Escape)){
			window.close();
		}
		//for restart
		if(Keyboard::isKeyPressed(Keyboard::Return)){
			paused = false; spd = 100; score = 10; time = 0.0f;
		}
		
		//timeit
		Time ag = clock.restart();
		if (!paused){
		spd += 0.01;
		//cat control
		if(pressable){
		if(Keyboard::isKeyPressed(Keyboard::Left)){
			if(cat.getPosition().x > 456){
				cat.setPosition(cat.getPosition().x-177, 600); cPos--;
			}
			pressable = false;
		}
		if(Keyboard::isKeyPressed(Keyboard::Right)){
			if(cat.getPosition().x < 810){
				cat.setPosition(cat.getPosition().x+177, 600); cPos++;
			}
			pressable = false;
		}
	}
		//move rats pertime
		for(int i=0; i<3; i++){
			rat[i].setPosition((rat[i].getPosition().x), (rat[i].getPosition().y + spd*ag.asSeconds()));
			//detect collision between rat and cat
			if(rPos[i]==cPos && rat[i].getPosition().y < 700 && rat[i].getPosition().y > 600){
				score += 1;	rat[i].setPosition(pos(i*10), 0);
			}
			//let rats switch sides incase out of screen
			if(rat[i].getPosition().y>760){
				rat[i].setPosition(pos(i*10), 0); score-=5;
			}
		}
		time+=ag.asSeconds(); inTime = time;
		
		if(score<0){
			endit.setString("Press enter to restart"); paused = true;
			endit.setPosition(456, 300);
			
		}
		
		window.clear();
		// draw all now
		 
	    //background
		window.draw(cover1);
	    window.draw(cover2);
	    window.draw(cover3);
	   
	    window.draw(scTxt);
	    
		window.draw(cat);
		
		if(paused){
			window.draw(endit);
		}
		
		for (int i = 0; i<3; i++){
		window.draw(rat[i]);
	   }
	  
	   
	   // display
	   window.display();
	}
}
	return 0;
}
int pos(int gen){
	srand(time(0)*gen);
	int dm = (rand() % 3)+1, ps;
	switch(dm){
		case 1:{
			ps = 456;
			rPos[gen/10] = dm;
			break;
		}
		case 2:{
			ps = 638;
			rPos[gen/10] = dm;
			break;
		}
		case 3:{
			ps = 820;
			rPos[gen/10] = dm;
			break;
		}
	}
	return ps;
}
