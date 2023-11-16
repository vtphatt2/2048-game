#include "header/game.hpp"

void Game::leftShift() {
    for (int i = 0 ; i < 4 ; ++i) 
    {
        for (int j = 0 ; j < 4 ; ++j)
        {
            if (arr[i][j] != 0)
            {
                for (int z = j + 1 ; z < 4 ; ++z)
                {
                    if (arr[i][z] == arr[i][j])
                    {
                        arr[i][j] *= 2;
                        arr[i][z] = 0;
                        j = z;
                        break;
                    }
                    if (arr[i][z] != 0) break;
                }
            }
        }
        for (int j = 0 ; j < 4 ; ++j)
        {
            if (arr[i][j] == 0) 
            {
                int z = j + 1;
                while (z < 4 && arr[i][z] == 0) ++z;
                if (z < 4)
                {
                    arr[i][j] = arr[i][z];
                    arr[i][z] = 0;
                }
            }
        }
    }
}

void Game::rightShift() {
    for (int i = 0 ; i < 4 ; ++i) 
    {
        for (int j = 3 ; j >= 0 ; --j)
        {
            if (arr[i][j] != 0)
            {
                for (int z = j - 1 ; z >= 0 ; --z)
                {
                    if (arr[i][z] == arr[i][j])
                    {
                        arr[i][j] *= 2;
                        arr[i][z] = 0;
                        j = z;
                        break;
                    }
                    if (arr[i][z] != 0) break;
                }
            }
        }
        for (int j = 3 ; j >= 0 ; --j)
        {
            if (arr[i][j] == 0) 
            {
                int z = j - 1;
                while (z >= 0 && arr[i][z] == 0) --z;
                if (z >= 0)
                {
                    arr[i][j] = arr[i][z];
                    arr[i][z] = 0;
                }
            }
        }
    }
}

void Game::upShift() {
    for (int j = 0 ; j < 4 ; ++j) 
    {
        for (int i = 0 ; i < 4 ; ++i)
        {
            if (arr[i][j] != 0)
            {
                for (int z = i + 1 ; z < 4 ; ++z)
                {
                    if (arr[i][j] == arr[z][j])
                    {
                        arr[i][j] *= 2;
                        arr[z][j] = 0;
                        i = z;
                        break;
                    }
                    if (arr[z][j] != 0) break;
                }
            }
        }
        for (int i = 0 ; i < 4 ; ++i)
        {
            if (arr[i][j] == 0) 
            {
                int z = i + 1;
                while (z < 4 && arr[z][j] == 0) ++z;
                if (z < 4)
                {
                    arr[i][j] = arr[z][j];
                    arr[z][j] = 0;
                }
            }
        }
    }
}

void Game::downShift() {
    for (int j = 0 ; j < 4 ; ++j) 
    {
        for (int i = 3 ; i >= 0 ; --i)
        {
            if (arr[i][j] != 0)
            {
                for (int z = i - 1 ; z >= 0 ; --z)
                {
                    if (arr[i][j] == arr[z][j])
                    {
                        arr[i][j] *= 2;
                        arr[z][j] = 0;
                        i = z;
                        break;
                    }
                    if (arr[z][j] != 0) break;
                }
            }
        }
        for (int i = 3 ; i >= 0 ; --i)
        {
            if (arr[i][j] == 0) 
            {
                int z = i - 1;
                while (z >= 0 && arr[z][j] == 0) --z;
                if (z >= 0)
                {
                    arr[i][j] = arr[z][j];
                    arr[z][j] = 0;
                }
            }
        }
    }
}
