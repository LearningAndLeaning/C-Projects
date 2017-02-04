#include "MazePerson.h"
#include <iostream>

using namespace std;


MazePerson::MazePerson(MazeMap* maze)
{
	this->MapPointer = maze->GetMapPointer();
	Exit_Position = maze->Get_Exit_Positon();
	Steps = 0;
}

void MazePerson::SetPersonInitPos(int x, int y,MazeMap* mazemap)
{
	int max_x, max_y;
	max_x = mazemap->GetMapCols();
	max_y = mazemap->GetMapRows();
	int** MapPointer = mazemap->GetMapPointer();

	if (x > max_x || y > max_y)
		cout << "初始位置超出地图范围" << endl;
	else
	{
		if (MapPointer[y][x] == 0)
			cout << "初始位置是墙，不合理" << endl;
		if (MapPointer[y][x] == 1)
		{
			unsigned long numWrite;
			CurrentPos.X = x;
			CurrentPos.Y = y;
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			FillConsoleOutputCharacter(handle, this->Person_Symbol, sizeof(this->Person_Symbol), CurrentPos, &numWrite);
		}
	}
}

void MazePerson::SetPersonSymbol(char symbol)
{
	this->Person_Symbol = symbol;
}

bool MazePerson::MoveUp()
{
	unsigned long numWrite;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

 	if (MapPointer[CurrentPos.Y-1][CurrentPos.X] == ROAD)
	{
		//更新游戏角色的走向
		this->Peson_Move_Direct = 'U';
		FillConsoleOutputCharacter(handle, ' ', sizeof(' '), CurrentPos, &numWrite);
		CurrentPos.Y -= 1;
		FillConsoleOutputCharacter(handle, this->Person_Symbol, sizeof(this->Person_Symbol), CurrentPos, &numWrite);

		Sleep(500);
		return true;
	}

	else
	{
		return false;
	}

}

bool MazePerson::MoveDown()
{
	unsigned long numWrite;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	if (MapPointer[CurrentPos.Y+1][CurrentPos.X] == ROAD)
	{
		//更新游戏角色的走向
		this->Peson_Move_Direct = 'D';
		FillConsoleOutputCharacter(handle, ' ', sizeof(' '), CurrentPos, &numWrite);
		CurrentPos.Y += 1;
		FillConsoleOutputCharacter(handle, this->Person_Symbol, sizeof(this->Person_Symbol), CurrentPos, &numWrite);

		Sleep(500);
		return true;
	}

	else
	{
		return false;
	}
}

bool MazePerson::MoveLeft()
{
	unsigned long numWrite;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	if (MapPointer[CurrentPos.Y][CurrentPos.X-1] == ROAD)
	{
		//更新游戏角色的走向
		this->Peson_Move_Direct = 'L';
		FillConsoleOutputCharacter(handle, ' ', sizeof(' '), CurrentPos, &numWrite);
		CurrentPos.X -= 1;
		FillConsoleOutputCharacter(handle, this->Person_Symbol, sizeof(this->Person_Symbol), CurrentPos, &numWrite);

		Sleep(500);
		return true;
	}

	else
	{
		return false;
	}
}

bool MazePerson::MoveRight()
{
	unsigned long numWrite;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	if (MapPointer[CurrentPos.Y][CurrentPos.X+1] == ROAD)
	{
		//更新游戏角色的走向
		this->Peson_Move_Direct = 'R';
		FillConsoleOutputCharacter(handle, ' ', sizeof(' '), CurrentPos, &numWrite);
		CurrentPos.X += 1;
		FillConsoleOutputCharacter(handle, this->Person_Symbol, sizeof(this->Person_Symbol), CurrentPos, &numWrite);

		Sleep(500);
		return true;
	}

	else
	{
		return false;
	}
}




void MazePerson::PersonMove(char& Direction)
{
	while (1)
	{
		if (CurrentPos.X == Exit_Position.X&&CurrentPos.Y == Exit_Position.Y)
		{

			cout << "您一共用了 " << Steps << " 步走出迷宫！" << endl;
			cout << "Bye-bye~~" << endl;
			cout << endl;
			break;
			system("pause");

		}
		else
		{
			switch (Direction)
			{
				/*在 逻辑|| 运算中，若当前判断表达式的值为真，则不再去执行后面的表达式*/
				/*这里用来设定判断走向的优先级*/
			case 'U':
				MoveLeft() || MoveUp() || MoveRight() || MoveDown();
				break;
			case 'D':
				MoveRight() || MoveDown() || MoveLeft() || MoveUp();
				break;
			case 'L':
				MoveDown() || MoveLeft() || MoveUp() || MoveRight();
				break;
			case 'R':
				MoveUp() || MoveRight() || MoveDown() || MoveLeft();
				break;
			default:
				break;
			}
		}

		Steps++;
	}
}

void MazePerson::PersonStart()
{
    this->Peson_Move_Direct = 'R';//进入迷宫肯定要有一个初始的走向,这里默认向右(屏幕的“右”)
	this->PersonMove(Peson_Move_Direct);
}
