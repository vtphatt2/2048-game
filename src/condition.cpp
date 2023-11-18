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

bool Game::isLose() {
    if (!isFull()) return false;

    for (int i = 0 ; i < 4 ; ++i)
    {
        for (int j = 0 ; j < 4 ; ++j)
        {
            for (int z = j + 1 ; z < 4 ; ++z)
            {
                if (arr[i][z] == 0) continue;
                if (arr[i][z] == arr[i][j]) return false;
                else break;
            }
        }
    }

    for (int j = 0 ; j < 4 ; ++j) 
    {
        for (int i = 0 ; i < 4 ; ++i)
        {
            for (int z = i + 1 ; z < 4 ; ++z)
            {
                if (arr[z][j] == 0) continue;
                if (arr[z][j] == arr[i][j]) return false;
                else break;
            }
        }
    }
    return true;
}
