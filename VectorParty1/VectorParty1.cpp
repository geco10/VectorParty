#include <SFML/Graphics.hpp>
#include"DualVector.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "Lesson 2. kychka-pc.ru");
	DualVector base,rot;
	base.setCartesian(100,100);
	rot.setPolar(50, 1);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		DualVector line = base + rot;
		LineWithWidth rt;
		rt.setWidth(5);
		rt.setFillColor(sf::Color::Green);
		rt.setPoints(line.tosf(), base.tosf());
		rot.getPhi(rot.getPhi() - 0.05);
		rt.setPoints(base.tosf(), line.tosf());
		rot.setPhi(rot.getPhi() + 0.05);
		window.clear();
		window.draw(rt);
		window.draw(rot);
		window.draw(base);
		window.draw(line);
		window.display();
	}

	return 0;
}