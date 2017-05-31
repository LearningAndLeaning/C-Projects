#include "Game.h"
#include <time.h>

void gotoxy(int x, int y)
{
	COORD loc = { x, y };
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, loc);
}

Snake::Snake()
{
	speed = 200;
	score = 0;
}

void Snake::win32_output(COORD pos,char symbol)
{
	unsigned long numWrite;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	FillConsoleOutputCharacter(handle, symbol, sizeof(symbol), pos, &numWrite);
}
void Snake::init(Map* map)
{
	towards = 'w';//初始默认小蛇往上走

	head_pos.X = 1;
	head_pos.Y = map->height - 2;
	body.push_front(head_pos);
	tail_pos = head_pos;

	win32_output(head_pos,'@');
}
void Snake::fresh(COORD head)
{
	COORD new_head = head;
	win32_output(new_head, '@');
	win32_output(tail_pos, ' ');

	body.push_front(new_head);
	body.pop_back();

	head_pos = body.front();
	tail_pos = body.back();
}
void Snake::move_up()
{
	COORD new_head;
	new_head.X = head_pos.X;
	new_head.Y = head_pos.Y - 1;

	fresh(new_head);
	Sleep(speed);
}
void Snake::move_left()
{
	COORD new_head;
	new_head.X = head_pos.X - 1;
	new_head.Y = head_pos.Y;

	fresh(new_head);
	Sleep(speed);

}
void Snake::move_right()
{
	COORD new_head;
	new_head.X = head_pos.X + 1;
	new_head.Y = head_pos.Y;

	fresh(new_head);
	Sleep(speed);

}
void Snake::move_down()
{
	COORD new_head;
	new_head.X = head_pos.X ;
	new_head.Y = head_pos.Y + 1;

	fresh(new_head);
	Sleep(speed);

}

bool Snake::move(Map* map,Food* food)
{
	if (_kbhit())
	{
		towards = _getch();
		fflush(stdin);
	}

	switch (towards)
	{
	case 'w':move_up();	   break;
	case 's':move_down();  break;
	case 'a':move_left();  break;
	case 'd':move_right(); break;
	default:
		std::cout << "error";
		return 0;
		break;
	}

	if (dead(map))
	{
		gotoxy(50, 15);
		cout << "game over !" << endl;
		return 1;
	}
	if (eat(food))
	{
		if (growth(food))
		{
			speed_up();
			score += 10;
			gotoxy(50, 10);
			cout << "score: " << score << endl;
			food->destroy();
			food->create(map,this);

			return 0;
		}
	}

	return 0;
}


bool Snake::dead(Map* map)
{
	int n = 0;
	if (head_pos.X == 0 || head_pos.X == map->width - 1 || head_pos.Y == 0 || head_pos.Y == map->height - 1)
	{
		return 1;
	}

	for (list<COORD>::iterator it = this->body.begin(); it != this->body.end(); it++)
	{
		n++;
		if (n == 1)
			continue;
		if (head_pos.X == (*it).X && head_pos.Y == (*it).Y)
		{
			return 1;
		}
	}

	return 0;
}

bool Snake::eat(Food* food)
{
	if (head_pos.X == food->pos.X && head_pos.Y == food->pos.Y)
		return 1;
	else
		return 0;
}

bool Snake::growth(Food* food)
{
	COORD new_tail;
	if (eat(food))
	{
		switch (towards)
		{
		case'w':new_tail.X = body.back().X; new_tail.Y = body.back().Y + 1; break;
		case'a':new_tail.X = body.back().X + 1; new_tail.Y = body.back().Y; break;
		case's':new_tail.X = body.back().X; new_tail.Y = body.back().Y - 1; break;
		case'd':new_tail.X = body.back().X - 1; new_tail.Y = body.back().Y; break;
		default:
			break;
		}
		body.push_back(new_tail);

		return 1;
	}

	return 0;
}

void Food::create(Map* map,Snake* snake)
{
	srand(time(NULL));
	int flag=0;
	for (;;)
	{
		pos.X = rand() % (map->width - 2)+1;
		pos.Y = rand() % (map->height - 2)+1;

		for (list<COORD>::iterator it = snake->body.begin(); it != snake->body.end(); it++)
		{
			if (pos.X == (*it).X && pos.Y == (*it).Y)
			{
				flag = 1;
				break;
			}
		}

		if (flag == 0)
		{
			unsigned long numWrite;
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			FillConsoleOutputCharacter(handle, '$', sizeof('$'), pos, &numWrite);

			break;
		}
	}
}

void Food::destroy()
{
	unsigned long numWrite;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	FillConsoleOutputCharacter(handle, '@', sizeof('@'), pos, &numWrite);
}

void Snake::speed_up()
{
	if (speed < 30)
		speed = 25;
	else speed = speed - 5;
}