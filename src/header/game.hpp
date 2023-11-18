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

        void run();
        void handleEvent();
        void update();
        void render();

        void initializeNewCell();
        void leftShift();
        void rightShift();
        void upShift();
        void downShift();
        void fillColorCells();
        void scaleText();

        bool isFull();
        bool isWin();
        bool isLose();

    private :
        sf::RenderWindow* window;
        sf::Event event;

        sf::RectangleShape rect;

        sf::Font font;
        sf::RectangleShape square[16];
        sf::Text text[16];
        sf::Text winText;
        sf::Text loseText;

        bool isMove;

        int** arr;
        int** sub_arr;
};

#endif // GAME_HPP