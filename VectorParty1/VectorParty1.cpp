#include <SFML/Graphics.hpp>
#include"DualVector.h"
#include<math.h>
DualVector fixedStep(DualVector center,int radius){
	if (center.y - radius <= 0)return DualVector(1, -1);
	else return DualVector(1, 1);
}
int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Lesson 2. kychka-pc.ru");
	DualVector base, rt,dir;
	base.setCartesian(250, 250);
	rt.setPolar(60, 0);
	dir.setPolar(0.05, -70);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		DualVector d = fixedStep(base,60);
		dir.x = dir.x * d.x;
		dir.y = dir.y * d.y;
		base = dir+base;
		DualVector rotl = base + rt;
		rt.setPhi(rt.getPhi()+0.05);
		LineWithWidth rot;
		rot.setWidth(5);
		rot.setFillColor(sf::Color(sin(rt.getPhi()) * 255, 1 / tan(rt.getPhi()), cos(rt.getPhi()) * 255));
		rot.setPoints(base.tosf(),rotl.tosf());
		sf::CircleShape ring(60);
		ring.setFillColor(sf::Color(cos(rt.getPhi()) * 255, sin(rt.getPhi()), 1 / tan(rt.getPhi()) * 255));
		ring.setPosition(base.x - 60, base.y - 60);
		sf::CircleShape center(10);
		center.setFillColor(sf::Color::Black);
		center.setPosition(base.x - 10, base.y - 10);
		//if()
		window.clear();
		window.draw(ring);
		window.draw(rot);
		window.draw(center);
		window.display();
	}

	return 0;
}