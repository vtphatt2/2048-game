#include "header/game.hpp"

bool Game::isFull() {
    for (int i = 0 ; i < 4 ; ++i)
    {
        for (int j = 0 ; j < 4 ; ++j)
        {
            if (arr[i][j] == 0) return false;
        }
    }
    return true;
}

bool Game::isWin() {
    for (int i = 0 ; i < 4 ; ++i)
    {
        for (int j = 0 ; j < 4 ; ++j)
        {
            if (arr[i][j] == 2048) return true;
        }
    }
    return false;
}