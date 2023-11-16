#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Game {
    public :
        Game();
        ~Game();
        void initShape();
        void run();
        void handleEvent();
        void update();
        void render();

    private :
        sf::RenderWindow* window;
        sf::Event event;

        sf::RectangleShape rect;

        sf::Font font;
        sf::RectangleShape square[16];
        sf::Text text[16];
};

#endif // GAME_HPP