#ifndef SNAKEBOARD_H
#define SNAKEBOARD_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace sf;
using namespace std;

class SnakeBoard 
{
    public:
        SnakeBoard(int sizeX, int sizeY, int rows, int columns, float width, float height); 
        //constructor (sizeX of inner screen, sizeY of inner screen, desired number of rows,
        //desired number of columns, width of full screen, height of full screen)
        VertexArray getScreen();
        float getWidth();
        float getHeight();
    private:
        VertexArray m_screen;
        float m_width;
        float m_height;
};

#endif