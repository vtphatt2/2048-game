#include "header/game.hpp"

Game::Game() : window(new sf::RenderWindow(sf::VideoMode(800, 600), "2048 GAME")) {
    window->setFramerateLimit(120);
    setup();
    initShape();
}

Game::~Game() {
    delete window;
    for (int i = 0 ; i < 4 ; ++i) 
        delete[] arr[i];
    delete[] arr;
    std::cout << "window pointer was deallocated !\n";
}

void Game::run() {
    while (window->isOpen()) 
    {
        handleEvent();
        update();
        render();
    }
}

void Game::handleEvent() {
    while (window->pollEvent(event)) 
    {
        switch (event.type) 
        {
            case sf::Event::Closed :
                window->close();
                break;

            case sf::Event::KeyPressed :
                if (isWin()) break;
                switch (event.key.code)
                {
                    case sf::Keyboard::Left :
                        leftShift();
                        initializeNewCell();
                        break;

                    case sf::Keyboard::Right :
                        rightShift();
                        initializeNewCell();
                        break;

                    case sf::Keyboard::Up :
                        upShift();
                        initializeNewCell();
                        break;

                    case sf::Keyboard::Down :
                        downShift();
                        initializeNewCell();
                        break;

                    default :
                        break;
                } 
                break;

            default :
                break;
        }
    }
}

void Game::update() {
    for (int i = 0 ; i < 4 ; ++i) 
    {
        for (int j = 0 ; j < 4 ; ++j) 
        {
            if (arr[i][j] == 0) 
                text[4 * i + j].setString("");
            else 
                text[4 * i + j].setString(std::to_string(arr[i][j]));
        }
    }

    fillColorCells();
    scaleText();
}

void Game::render() {
    window->clear(sf::Color(0x8F, 0x5A, 0x3C));

    window->draw(rect);
    for (int i = 0 ; i < 16 ; ++i) 
    {
        window->draw(square[i]);
        window->draw(text[i]);
    }

    if (isWin())
        window->draw(winText);
    else if (isLose())
        window->draw(loseText);

    window->display();
}
