#include "header/game.hpp"

Game::Game() : window(new sf::RenderWindow(sf::VideoMode(800, 600), "2048 GAME")) {
    window->setFramerateLimit(60);
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

            case sf::Event::KeyPressed :
                if (isWin()) return ;
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

    for (int i = 0 ; i < 4 ; ++i)
    {
        for (int j = 0 ; j < 4 ; ++j)
        {
            switch (arr[i][j]) 
            {
                case 2 :
                    square[4 * i + j].setFillColor(sf::Color(0xD0, 0xCF, 0xCF));
                    break;

                case 4 :
                    square[4 * i + j].setFillColor(sf::Color(0xD4, 0xD1, 0x79));
                    break;

                case 8 :
                    square[4 * i + j].setFillColor(sf::Color(0xFD, 0x76, 0x4C));
                    break;
                
                case 16 :
                    square[4 * i + j].setFillColor(sf::Color(0xD4, 0x53, 0x44));
                    break;

                case 32 :
                    square[4 * i + j].setFillColor(sf::Color(0xD6, 0x6B, 0x54));
                    break;
                
                case 64 :
                    square[4 * i + j].setFillColor(sf::Color(0xC8, 0x64, 0x02));
                    break;

                case 128 :
                    square[4 * i + j].setFillColor(sf::Color(0xAC, 0xC8, 0x02));
                    break;

                case 256 :
                    square[4 * i + j].setFillColor(sf::Color(0x02, 0xC8, 0x2E));
                    break;
                
                case 512 :
                    square[4 * i + j].setFillColor(sf::Color(0x02, 0xED, 0xC8));
                    break;

                case 1024 :
                    square[4 * i + j].setFillColor(sf::Color(0x02, 0x51, 0xC8));
                    break;

                case 2048 :
                    square[4 * i + j].setFillColor(sf::Color(0xC8, 0x32, 0x02));
                    break;

                default :
                    square[4 * i + j].setFillColor(sf::Color::White);
                    break;  
            }
        }
    }

    for (int i = 0 ; i < 16 ; ++i) 
    {
        sf::FloatRect textBounds = text[i].getLocalBounds();
        text[i].setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
        text[i].setPosition(square[i].getPosition().x + square[i].getSize().x / 2.0f, square[i].getPosition().y + square[i].getSize().y / 2.0f);
    }

}

void Game::render() {
    window->clear(sf::Color(0x8F, 0x5A, 0x3C));

    window->draw(rect);
    for(int i = 0 ; i < 16 ; ++i) 
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
