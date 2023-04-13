#include <SFML/Graphics.hpp>
#include"DualVector.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "Lesson 2. kychka-pc.ru");
	DualVector base, rt,rt1;
	base.setCartesian(100, 100);
	rt.setPolar(60, 0);
	rt1.setPolar(20, 0);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		DualVector rotl = base + rt;
		rt.setPhi(rt.getPhi() + 0.05);
		LineWithWidth rot;
		rot.setWidth(5);
		rot.setFillColor(sf::Color::Green);
		rot.setPoints(base.tosf(),rotl.tosf() );
		sf::CircleShape ring();
		ring.setFillColor(sf::Color(178, 179, 189));
		set
		window.clear();
		window.draw(rot);
		window.display();
	}

	return 0;
}