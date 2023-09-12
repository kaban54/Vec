#include "vec.h"


sf::Vector2f Vec::GetArrow1 () const {
    return sf::Vector2f (x + (-x - y) * 0.05, y + (-y + x) * 0.05);
}

sf::Vector2f Vec::GetArrow2 () const {
    return sf::Vector2f (x + (-x + y) * 0.05, y + (-y - x) * 0.05);
}

sf::Vector2f CoordSys::GetCoords (const Vec& vec) const {
    return sf::Vector2f (originX + scaleX * vec.GetX(), originY + scaleY * vec.GetY());
}

sf::Vector2f CoordSys::GetCoords (const sf::Vector2f& vec2f) const {
    return sf::Vector2f (originX + scaleX * vec2f.x, originY + scaleY * vec2f.y);
}


void VecDraw (sf::RenderWindow& window, const CoordSys& coordsys, const Vec& vec) {

    sf::Vector2f vec_coords = coordsys.GetCoords (vec);
    sf::Vector2f ar1_coords = coordsys.GetCoords (vec.GetArrow1());
    sf::Vector2f ar2_coords = coordsys.GetCoords (vec.GetArrow2());

    sf::Vertex vec_lines [] = 
    {
        sf::Vertex (coordsys.GetOrigin (), vec.GetColor()),
        sf::Vertex (vec_coords           , vec.GetColor()),
        sf::Vertex (vec_coords           , vec.GetColor()),
        sf::Vertex (ar1_coords           , vec.GetColor()),
        sf::Vertex (vec_coords           , vec.GetColor()),
        sf::Vertex (ar2_coords           , vec.GetColor())
    };

    window.draw (vec_lines, 6, sf::Lines);
}
