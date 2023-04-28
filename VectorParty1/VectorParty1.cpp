#include <SFML/Graphics.hpp>
#include"DualVector.h"
#include<math.h>
bool fixedStep(DualVector base, DualVector rt, DualVector rt1){
	sf::Vector2f a=base.tosf(), b = base.tosf() + rt.tosf(), c=base.tosf()+rt1.tosf();
	if (a.x <= 0||a.y<=0||a.x>=500||a.y>=500)return false;
	if (b.x <= 0 || b.y <= 0 || b.x >= 500 || b.y >= 500)return false;
	if (c.x <= 0 || c.y <= 0 || c.x >= 500 || c.y >= 500)return false;
	return true;
}
int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Lesson 2. kychka-pc.ru");
	DualVector base, rt,rt1;
	base.setCartesian(250, 250);
	rt.setPolar(40, 0);
	rt1.setPolar(40, 90);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Down)
				{
					DualVector t1 = DualVector(base.x, base.y + 5);
					if(fixedStep(t1,rt,rt1))
					  base.y = base.y + 5;
				}
				if (event.key.code == sf::Keyboard::Up)
				{
					DualVector t1 = DualVector(base.x, base.y - 5);
					if (fixedStep(t1, rt, rt1))
					base.y = base.y - 5;
				}
				if (event.key.code == sf::Keyboard::Right)
				{
					DualVector t1 = DualVector(base.x+5, base.y);
					if (fixedStep(t1, rt, rt1))
					base.x = base.x + 5;
				}
				if (event.key.code == sf::Keyboard::Left)
				{
					DualVector t1 = DualVector(base.x-5, base.y);
					if (fixedStep(t1, rt, rt1))
					base.x = base.x - 5;
				}
				if (event.key.code == sf::Keyboard::A)
				{
					if(fixedStep(base,rt,rt1))
					  rt.setPhi(rt.getPhi()+2);
				}
				if (event.key.code == sf::Keyboard::S)
				{
					if(fixedStep(base, rt, rt1))
					  rt1.setPhi(rt1.getPhi() + 2);
				}
			}

		}
		DualVector rotl = base + rt,rotl1=base+rt1;
		LineWithWidth rot,rot1;
		rot.setWidth(5);
		rot1.setWidth(5);
		rot.setFillColor(sf::Color(sin(rt.getPhi()) * 255, 1 / tan(rt.getPhi()), cos(rt.getPhi()) * 255));
		rot.setPoints(base.tosf(),rotl.tosf());
		rot1.setFillColor(sf::Color(sin(rt.getPhi()) * 255, 1 / tan(rt.getPhi()), cos(rt.getPhi()) * 255));
		rot1.setPoints(base.tosf(), rotl1.tosf());
		LineWithWidth line;
		line.setWidth(5);
		line.setFillColor(sf::Color(tan(base.getPhi()) * 255, 1 / tan(rt.getPhi()), cos(base.getPhi()) * 255));
		line.setPoints(rotl.tosf(), rotl1.tosf());
		window.clear();
		window.draw(rot1);
		window.draw(rot);
		window.draw(line);
		window.display();
	}

	return 0;
}







//#include <SFML/Graphics.hpp>
//#include"DualVector.h"
//#include"Multiangle.h"
//#include<math.h>
//bool fixedStep(DualVector base, DualVector rt, DualVector rt1) {
//	sf::Vector2f a = base.tosf(), b = base.tosf() + rt.tosf(), c = base.tosf() + rt1.tosf();
//	if (a.x <= 0 || a.y <= 0 || a.x >= 500 || a.y >= 500)return false;
//	if (b.x <= 0 || b.y <= 0 || b.x >= 500 || b.y >= 500)return false;
//	if (c.x <= 0 || c.y <= 0 || c.x >= 500 || c.y >= 500)return false;
//	return true;
//}
//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(500, 500), "Lesson 2. kychka-pc.ru");
//	DualVector base, angle;
//	base.setCartesian(250, 250);
//	angle.setPolar(80, 7);
//	Multiangle shape(8, base.tosf(), angle, base);
//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//			if (event.type == sf::Event::KeyPressed)
//			{
//				if (event.key.code == sf::Keyboard::Right)
//				{
//					shape.move(sf::Vector2f(5, 0));
//				}
//				if (event.key.code == sf::Keyboard::Left)
//				{
//					shape.move(sf::Vector2f(-5, 0));
//				}
//				if (event.key.code == sf::Keyboard::Down)
//				{
//					shape.move(sf::Vector2f(0, 5));
//				}
//				if (event.key.code == sf::Keyboard::Up)
//				{
//					shape.move(sf::Vector2f(0, -5));
//				}
//				if (event.key.code == sf::Keyboard::A)
//				{
//					shape.rotate(3);
//				}
//				if (event.key.code == sf::Keyboard::S)
//				{
//					shape.rotate(-3);
//				}
//				if (event.key.code == sf::Keyboard::Q)
//				{
//					shape.dec();
//				}
//				if (event.key.code == sf::Keyboard::W)
//				{
//					shape.inc();
//				}
//			}
//
//		}
//
//		window.clear();
//		window.draw(shape);
//		window.display();
//	}
//
//	return 0;
//}