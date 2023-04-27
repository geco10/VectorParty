#pragma once
#include"DualVector.h"
#include<vector>
#include<SFML/Graphics.hpp>
class Multiangle :public sf::Drawable
{
	int count;
	DualVector angle;
	DualVector base;
public:
	void inc();
	void dec();
	void rotate(int turn);
	void move(sf::Vector2f v);
	Multiangle(int count,DualVector angle,DualVector base);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
}; 