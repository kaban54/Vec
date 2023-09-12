#include "vec.h"

int main ()
{
    sf::RenderWindow window (sf::VideoMode (800, 800), "eee vector");

    Vec vec (3, 4, sf::Color::Blue);
    CoordSys cs (400, 400, 50, -50);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
            }
        }

        window.clear();

        VecDraw (window, cs, vec);

        window.display();
    }

    return 0;
}