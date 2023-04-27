#include "Multiangle.h"



void Multiangle::inc()
{
	count += 1;
}

void Multiangle::dec()
{
	if(count>1)
	  count--;
}

void Multiangle::rotate(int turn)
{
	angle.setPhi(angle.getPhi() + turn);
}

void Multiangle::move(sf::Vector2f v)
{
	base = base + v;
}

Multiangle::Multiangle(int count, DualVector angle,DualVector base)
{
	this->count = count;
	this->angle = angle;
	this->base = base;
}

void Multiangle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	DualVector deg = angle;
	std::vector<DualVector> rot;
	float step = 360. / count;
	for (int i = 0; i < count; i++){
		rot.push_back(base + deg);
		deg.setPhi(deg.getPhi() + step / 2);
		deg = DualVector(deg.x / 2, deg.y / 2);
		rot.push_back(base + deg);
		deg = DualVector(deg.x*2,deg.y*2);
		deg.setPhi(deg.getPhi() + step / 2);
	}
	for (int i = 0; i < rot.size()-1; i++)
	{
		LineWithWidth line;
		line.setWidth(4);
		line.setFillColor(sf::Color::Red);
		line.setPoints(rot[i].tosf(), rot[i + 1].tosf());
		target.draw(line);
	}
	LineWithWidth line;
	line.setWidth(4);
	line.setFillColor(sf::Color::Red);
	line.setPoints(rot[rot.size()-1].tosf(), rot[0].tosf());
	target.draw(line);
}
