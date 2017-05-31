#ifndef FOOD_H
#define FOOD_H

#include "Game.h"
#include "Map.h"

class Snake;

class Food
{
public:
	void init();
	void create(Map* map,Snake* snake);
	void destroy();

	COORD pos;
private:
	char symbol;
};




#endif