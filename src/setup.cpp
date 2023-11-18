#include "header/game.hpp"
#include <cmath>

int randomCell() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, 3);
    return distribution(gen);
}

void Game::initializeNewCell() {
    if (isFull()) return ;

    int x = randomCell();
    int y = randomCell();
    while (arr[x][y] != 0)
    {
        x = randomCell();
        y = randomCell();
    } 
    arr[x][y] = 2;

    isMove = false;
}

void Game::initShape() {
    rect.setSize(sf::Vector2f(410, 410));
    rect.setFillColor(sf::Color(0x61, 0x37, 0x31));
    rect.setPosition(195, 95);

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
        text[i].setCharacterSize(40);
        text[i].setFillColor(sf::Color(0xD6, 0xB0, 0x8D));
        text[i].setOutlineThickness(3);
        text[i].setOutlineColor(sf::Color(0x37, 0x00, 0x00));
    }

    winText.setFont(font);
    winText.setCharacterSize(80);
    winText.setFillColor(sf::Color(0xD6, 0xB0, 0x8D));
    winText.setOutlineThickness(4);
    winText.setOutlineColor(sf::Color(0x37, 0x00, 0x00));
    winText.setString("Congratulation !");
    sf::FloatRect textBounds = winText.getLocalBounds();
    winText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    winText.setPosition(window->getSize().x / 2.0f, window->getSize().y / 1.1f);

    loseText.setFont(font);
    loseText.setCharacterSize(80);
    loseText.setFillColor(sf::Color(0xD6, 0xB0, 0x8D));
    loseText.setOutlineThickness(4);
    loseText.setOutlineColor(sf::Color(0x37, 0x00, 0x00));
    loseText.setString("You lose !");
    textBounds = loseText.getLocalBounds();
    loseText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    loseText.setPosition(window->getSize().x / 2.0f, window->getSize().y / 1.1f);
}

void Game::setup() {
    font.loadFromFile("../resource/Arial.ttf");

    arr = new int*[4];
    sub_arr = new int*[4];
    for (int i = 0 ; i < 4 ; ++i) 
    {
        arr[i] = new int[4];
        sub_arr[i] = new int[4]; 
        for (int j = 0 ; j < 4 ; ++j)
            arr[i][j] = 0;
    }

    // for (int i = 0 ; i < 3 ; ++i) 
    // {
    //     for (int j = 0 ; j < 4 ; ++j)
    //     {
    //         arr[i][j] = std::pow(2, 4*i + j);
    //     }
    // }

    isMove = false;
    initializeNewCell();
    initializeNewCell();
}