#pragma once
#include <SFML/Graphics.hpp>

class LineWithWidth: public sf::RectangleShape
{
	float width;

public:
	void setPoints(sf::Vector2f a, sf::Vector2f b);
	float setWidth(float w);
	float getWidth() const;
};

