#include <SFML/Graphics.hpp>

#ifndef VEC_H
#define VEC_H

class Vec {
    public:

    double x;
    double y;
    sf::Color color;

    Vec (double x_, double y_, const sf::Color& color_ = sf::Color::White);

    sf::Vector2f GetArrow1 ();
    sf::Vector2f GetArrow2 ();
};

class CoordSys {
    public:

    double originX;
    double originY;
    double scaleX;
    double scaleY;

    CoordSys (double originX_, double originY_, double scaleX_, double scaleY_):
        originX (originX_),
        originY (originY_),
        scaleX (scaleX_),
        scaleY (scaleY_)
        {}

    sf::Vector2f GetCoords (const Vec& vec);

    sf::Vector2f GetCoords (const sf::Vector2f& vec2f);

    sf::Vector2f GetOrigin ();
};


Vec VecMul (const double c, const Vec *vec);
Vec VecSum (const Vec *vec1, const Vec *vec2);

void VecDraw (sf::RenderWindow& window, CoordSys& coordsys, Vec& vec);


#endif