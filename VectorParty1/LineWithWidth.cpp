#define _USE_MATH_DEFINES
#include "LineWithWidth.h"
#include "cmath"


void LineWithWidth::setPoints(sf::Vector2f a, sf::Vector2f b)
{
    sf::Vector2f direction = b - a;
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    float angle = atan2(direction.y, direction.x) * 180 / M_PI;

    setRotation(angle);
    setPosition(a);    
    setSize(sf::Vector2f(length, width));
    setOrigin(0, width/2);
}

float LineWithWidth::setWidth(float w)
{
    return width=w;
}

float LineWithWidth::getWidth() const
{
    return width;
}

