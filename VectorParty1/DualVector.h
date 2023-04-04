#pragma once
#include <cmath>
#include <sfml/Graphics.hpp>
#include "LineWithWidth.h"

class DualVector: public sf::Drawable
{
	float x=0, y=0;

public:
	DualVector() = default;
	DualVector(float x, float y);
	DualVector& setCartesian(float x, float y);
	DualVector& setPolar(float len, float phi);
	DualVector& setPhi(float phi);

	float getLen() const;
	float getPhi() const;

	sf::Vector2f tosf() const;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	DualVector operator+(const DualVector& other) const;
	DualVector operator+(const sf::Vector2f& other) const;

	static float rad_to_deg(float rad);
	static float deg_to_rad(float deg);
};