#include <iostream>
#include "Map.h"
#include "Game.h"
#include <stdlib.h>

void gotoxy(int x, int y);


int main()
{
LOOP:
	system("cls");
	Map* map = new Map;
	Snake* snake = new Snake;
	Food* food = new Food;

	gotoxy(50, 15);
	cout << "Ð¡Ð¡Ì°³ÔÉß" << endl;
	gotoxy(50, 20);
	cout << "Press SPACE to start gmae   :)" << endl;

	while (!_getch() == ' ');
	
	system("cls");

	map->drawmap(40,20);
	snake->init(map);
	food->create(map,snake);

	for (;;)
	{
		if (snake->move(map, food))
			break;
	}

	system("cls");
	gotoxy(50, 15);
	cout << "your final score : " << snake->score << endl;
	gotoxy(20, 20);
	cout << "if you want to restart the game,plese press the SPACE to return to the menu :)" << endl;

	delete snake;
	delete map;
	delete food;
END:if (_getch() == ' ')
	goto LOOP;
	else
		goto END;

}