#include "SnakeBoard.h"

SnakeBoard::SnakeBoard(int sizeX, int sizeY, int rows, int columns, float width, float height)
{
    m_height = height;
    m_width = width;
    m_screen.setPrimitiveType(Points);
    m_screen.resize(width*height);
    for(int j = 0; j < sizeX; j++)
    {
        for(int i = 0; i < sizeY; i++)
        {
            m_screen[j + i * sizeX].position = { ((width-sizeX)/2)+(float)j,((height-sizeY)/2)+(float)i };
            if((j % (2*(sizeX/rows)))-(sizeX/rows) <= 0 && (i % (2*(sizeY/columns)))-(sizeY/columns) <= 0)
            {
                m_screen[j + i * sizeX].color = { 1, 200, 32 };
            }
            else if((j % (2*(sizeX/rows)))-(sizeX/rows) >= 0 && (i % (2*(sizeY/columns)))-(sizeY/columns) <= 0)
            {
                m_screen[j + i * sizeX].color = { 1, 50, 32 };
            }
            else if((j % (2*(sizeX/rows)))-(sizeX/rows) <= 0 && (i % (2*(sizeY/columns)))-(sizeY/columns) >= 0)
            {
                m_screen[j + i * sizeX].color = { 1, 50, 32 };
            }
            else if((j % (2*(sizeX/rows)))-(sizeX/rows) >= 0 && (i % (2*(sizeY/columns)))-(sizeY/columns) >= 0)
            {
                m_screen[j + i * sizeX].color = { 1, 200, 32 };
            }
        }
    }
}

VertexArray SnakeBoard::getScreen()
{
    return m_screen;
}

float SnakeBoard::getWidth()
{
    return m_width;
}

float SnakeBoard::getHeight()
{
    return m_height;
}