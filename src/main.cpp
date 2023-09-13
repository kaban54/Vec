#include "vec.h"

int main ()
{
    sf::RenderWindow window (sf::VideoMode (1200, 1200), "eee vector");
    window.setFramerateLimit (120);

    Vec vec_spining (3, 4, sf::Color::Blue);
    Vec vec_mouse   (0, 0, sf::Color::Red);
    Vec vec3 = vec_spining - vec_mouse;
    Vec vec4 = -3 * vec_mouse;

    CoordSys cs1 (600, 600, 80, -80);
    CoordSys cs2 (400, 800, 20, 20);

    sf::Clock clk;
    double dt = 0;
    double spin_v = 180;

    bool mouse_pressed = 0;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent (event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    mouse_pressed = 1;
                    vec_mouse.Move (cs1.GetCoords (event.mouseButton.x, event.mouseButton.y));
                }
            }

            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    mouse_pressed = 0;
                }
            }

            if (mouse_pressed && event.type == sf::Event::MouseMoved) {
                vec_mouse.Move (cs1.GetCoords (event.mouseMove.x, event.mouseMove.y));
            }
        }

        dt = clk.restart().asSeconds();
        vec_spining.Rotate_deg (spin_v * dt);

        vec3 = vec_spining - vec_mouse;
        vec3.SetColor (sf::Color::Magenta);

        vec4 = -3 * vec_mouse;
        vec4.SetColor (sf::Color::Green);

        window.clear();

        VecDraw (window, cs1, vec_spining);
        VecDraw (window, cs2, vec_spining);
        VecDraw (window, cs1, vec_mouse);
        VecDraw (window, cs2, vec_mouse);
        VecDraw (window, cs1, vec3);
        VecDraw (window, cs2, vec4);

        window.display();
    }

    return 0;
}