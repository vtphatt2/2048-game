#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

int randomCell();

class Game {
    public :
        Game();
        ~Game();
        void initShape();
        void setup();
        void initializeNewCell();
        void leftShift();
        void rightShift();
        void upShift();
        void downShift();
        void run();
        void handleEvent();
        void update();
        void render();

        bool isFull();
        bool isWin();

    private :
        sf::RenderWindow* window;
        sf::Event event;

        sf::RectangleShape rect;

        sf::Font font;
        sf::RectangleShape square[16];
        sf::Text text[16];
        sf::Text winText;

        int** arr;
};

#endif // GAME_HPP