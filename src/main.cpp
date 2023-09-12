#include "vec.h"

int main ()
{
    sf::RenderWindow window (sf::VideoMode (800, 800), "eee vector");

    Vec vec (3, 4, sf::Color::Blue);
    Vec vec1 = -vec;
    Vec vec2 (1, 0);
    Vec vec3 = vec + vec2;
    Vec vec4 = vec2 * 5;
    Vec vec5 = 6 * vec2;
    Vec vec6 = vec / 0;

    vec1.SetColor (sf::Color::Red);
    CoordSys cs (400, 400, 50, -50);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent (event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
            }
        }

        window.clear();

        VecDraw (window, cs, vec);
        VecDraw (window, cs, vec1);
        VecDraw (window, cs, vec2);
        VecDraw (window, cs, vec3);
        VecDraw (window, cs, vec4);
        VecDraw (window, cs, vec5);
        VecDraw (window, cs, vec6);

        window.display();
    }

    return 0;
}