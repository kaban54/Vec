#ifndef VEC_H
#define VEC_H

#include <SFML/Graphics.hpp>
#include <cmath>

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

    Vec operator-() const {
        return Vec (-x, -y, color);
    }

    Vec operator+ (const Vec& vec2) const {
        return Vec (x + vec2.x, y + vec2.y);
    }

    Vec operator- (const Vec& vec2) const {
        return Vec (x - vec2.x, y - vec2.y);
    }

    Vec operator* (const double scalar) const {
        return Vec (x * scalar, y * scalar);
    }

    Vec operator/ (const double scalar) const {
        return Vec (x / scalar, y / scalar);
    }

    void operator+= (const Vec& vec2) {
        x += vec2.x;
        y += vec2.y;
    }

    void operator-= (const Vec& vec2) {
        x -= vec2.x;
        y -= vec2.y;
    }

    void operator*= (const double scalar) {
        x *= scalar;
        y *= scalar;
    }

    void operator/= (const double scalar) {
        x /= scalar;
        y /= scalar;
    }

    double operator, (const Vec& vec2) const {
        return x * vec2.x + y * vec2.y;
    }

    double GetLen () const {
        return std::sqrt (x * x + y * y);
    }

    void Normalize () {
        *this /= GetLen ();
    }

    Vec operator! () const {
        Vec ret = *this;
        ret.Normalize();
        return ret;
    }   
};

inline Vec operator* (const double scalar, const Vec& vec) {
    return vec * scalar;
}


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
};

void VecDraw (sf::RenderWindow& window, const CoordSys& coordsys, const Vec& vec);


#endif