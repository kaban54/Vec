#include "vec.h"

Vec::Vec (double x_, double y_, const sf::Color& color_) {
    x = x_;
    y = y_;
    color = color_;
}

sf::Vector2f Vec::GetArrow1 () {
    return sf::Vector2f (x + (-x - y) * 0.05, y + (-y + x) * 0.05);
}

sf::Vector2f Vec::GetArrow2 () {
    return sf::Vector2f (x + (-x + y) * 0.05, y + (-y - x) * 0.05);
}


Vec VecMul (const double c, const Vec *vec) {
    return Vec (vec -> x * c, vec -> y * c);
}

Vec VecSum (const Vec *vec1, const Vec *vec2) {
    return Vec (vec1 -> x + vec2 -> x, vec1 -> y + vec2 -> y);
}


sf::Vector2f CoordSys::GetCoords (const Vec& vec) {
    return sf::Vector2f (originX + scaleX * vec.x, originY + scaleY * vec.y);
}

sf::Vector2f CoordSys::GetCoords (const sf::Vector2f& vec2f) {
    return sf::Vector2f (originX + scaleX * vec2f.x, originY + scaleY * vec2f.y);
}

sf::Vector2f CoordSys::GetOrigin () {
    return sf::Vector2f (originX, originY);
}


void VecDraw (sf::RenderWindow& window, CoordSys& coordsys, Vec& vec) {

    sf::Vector2f vec_coords = coordsys.GetCoords (vec);
    sf::Vector2f ar1_coords = coordsys.GetCoords (vec.GetArrow1());
    sf::Vector2f ar2_coords = coordsys.GetCoords (vec.GetArrow2());

    sf::Vertex vec_lines [] = 
    {
        sf::Vertex (coordsys.GetOrigin (), vec.color),
        sf::Vertex (vec_coords           , vec.color),
        sf::Vertex (vec_coords           , vec.color),
        sf::Vertex (ar1_coords           , vec.color),
        sf::Vertex (vec_coords           , vec.color),
        sf::Vertex (ar2_coords           , vec.color)

    };

    window.draw (vec_lines, 6, sf::Lines);
}

