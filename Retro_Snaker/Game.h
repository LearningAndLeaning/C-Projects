#ifndef GAME_H
#define GAME_H

#include <list>
#include <windows.h>
#include "Map.h"
#include <conio.h>
#include "Food.h"
#include <iostream>

using namespace std;

class Snake
{
public:
	Snake();
	void init(Map* map);
	void move_up();
	void move_left();
	void move_right();
	void move_down();
	bool move(Map* map, Food* food);
	void fresh(COORD new_head);
	void win32_output(COORD pos, char symbol);
	bool growth(Food* food);
	bool eat(Food* food);
	bool dead(Map* map);
	void speed_up();

	int speed;
	int score;

	std::list<COORD> body;

private:
	char towards;
	COORD head_pos;
	COORD tail_pos;
};



#endif