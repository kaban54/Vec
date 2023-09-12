#include <SFML/Graphics.hpp>

#ifndef VEC_H
#define VEC_H

class CoordSys;

class Vec {
    double x;
    double y;
    sf::Color color;

    public:
    Vec (double x_, double y_, const sf::Color& color_ = sf::Color::White): 
        x (x_),
        y (y_),
        color (color_)
        {}

    double GetX () const {
        return x;
    }

    double GetY () const {
        return y;
    }

    sf::Color GetColor () const {
        return color;
    }

    void SetX (double x_) {
        x = x_;
    }

    void SetY (double y_) {
        y = y_;
    }

    void SetColor (const sf::Color& color_) {
        color = color_;
    }

    void Move (double x_, double y_) {
        x = x_;
        y = y_;
    }

    sf::Vector2f GetArrow1 () const;
    
    sf::Vector2f GetArrow2 () const;

    friend void VecDraw (sf::RenderWindow& window, const CoordSys& coordsys, const Vec& vec);
};

class CoordSys {
    double originX;
    double originY;
    double scaleX;
    double scaleY;

    public:
    CoordSys (double originX_, double originY_, double scaleX_, double scaleY_):
        originX (originX_),
        originY (originY_),
        scaleX (scaleX_),
        scaleY (scaleY_)
        {}

    double GetOriginX () const {
        return originX;
    }

    double GetOriginY () const {
        return originY;
    }

    double GetScaleX () const {
        return scaleX;
    }

    double GetScaleY () const {
        return scaleX;
    }

    void SetOriginX (double x) {
        originX = x;
    }

    void SetOriginY (double y) {
        originY = y;
    }

    void SetScaleX (double scalex) {
        scaleX = scalex;
    }

    void SetScaleY (double scaley) {
        scaleY = scaley;
    }

    void MoveOrigin (double x, double y) {
        originX = x;
        originY = y;
    }

    sf::Vector2f GetCoords (const Vec& vec) const;

    sf::Vector2f GetCoords (const sf::Vector2f& vec2f) const;

    sf::Vector2f GetOrigin () const {
        return sf::Vector2f (originX, originY);
    }

    friend void VecDraw (sf::RenderWindow& window, const CoordSys& coordsys, const Vec& vec);
};

void VecDraw (sf::RenderWindow& window, const CoordSys& coordsys, const Vec& vec);


#endif