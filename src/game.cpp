#include "header/game.hpp"

Game::Game() : window(new sf::RenderWindow(sf::VideoMode(800, 600), "2048 GAME")) {
    window->setFramerateLimit(60);
    font.loadFromFile("../resource/arial.ttf");
    initShape();
}

Game::~Game() {
    delete window;
    std::cout << "window pointer was deallocated !\n";
}

void Game::initShape() {
    rect.setSize(sf::Vector2f(400, 400));
    rect.setFillColor(sf::Color(0x61, 0x37, 0x31));
    rect.setPosition(200, 100);

    square[0].setPosition(200, 100);
    int a = 94; 
    int b = 8;
    // 4a + 3b = 400

    for (int i = 4 ; i <= 12 ; i += 4) 
    {
        square[i].setPosition(square[i - 4].getPosition().x, square[i - 4].getPosition().y + a + b);
    }

    for (int i = 1 ; i < 16 ; ++i) 
    {
        if (i % 4 != 0)
            square[i].setPosition(square[i - 1].getPosition().x + a + b, square[i - 1].getPosition().y);
    }


    for (int i = 0 ; i < 16 ; ++i) 
    {
        square[i].setSize(sf::Vector2f(94, 94));   

        text[i].setFont(font);    
        text[i].setCharacterSize(30);
        text[i].setFillColor(sf::Color::Red); 
        text[i].setString("10");
    }

    for (int i = 0 ; i < 16 ; ++i) 
    {
        sf::FloatRect textBounds = text[i].getLocalBounds();
        text[i].setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
        text[i].setPosition(square[i].getPosition().x + square[i].getSize().x / 2.0f, square[i].getPosition().y + square[i].getSize().y / 2.0f);
    }
}

void Game::run() {
    while (window->isOpen()) {
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

            default :
                break;
        }
    }
}

void Game::update() {

}

void Game::render() {
    window->clear(sf::Color(0x8F, 0x5A, 0x3C));

    window->draw(rect);
    for(int i = 0 ; i < 16 ; ++i) 
    {
        window->draw(square[i]);
        window->draw(text[i]);
    }

    window->display();
}