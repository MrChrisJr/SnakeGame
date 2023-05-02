#include "SnakeBoard.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace sf;
using namespace std;

int main() 
{
    //Initialize Window
    //Constructs and constrains window
    float width = sf::VideoMode::getDesktopMode().width;
	float height = sf::VideoMode::getDesktopMode().height;
	//View mainView(FloatRect(0.0f,0.0f,width, height));
	// Create a video mode object
	VideoMode vm(width, height);
	// Create and open a window for the game
	RenderWindow window(vm, "Snake Game!", Style::Default);

    /*Initialize what I need for the snake game board. 
    Made a class called SnakeBoard to build the board with specifications*/
    int sizeX = 1000;
    int sizeY = 600;
    int rows = 20; //these numbers create 50 by 50 pixel squares
    int columns = 12;
    SnakeBoard board(sizeX,sizeY,rows,columns,width,height);
    Vector2i snake; //
    Vector2i foodLocation; //dynamic food location (size of 1 for the single point of food)

    int directionToMove; // 1 == left, 2 == up, 3 == right, 4 == down
    int currDirection = 2; //Default to up for spawn;

    //window updates
    while(window.isOpen())
    {
        //Handle player inputs
        Event event;
        while(window.pollEvent(event))
		{
			if(event.type == Event::Closed)
			{
				window.close();
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
                if(currDirection == 1) { break; }
                directionToMove = 1;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
                if(currDirection == 2) { break; }
                directionToMove = 2;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
                if(currDirection == 3) { break; }
                directionToMove = 3;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
                if(currDirection == 4) { break; }
                directionToMove = 4;
            }
        }
    //Updates
        

    
    //Draw window
        window.clear();
        window.draw(board.getScreen());
        window.display();
    }
    return 0;
    
}