#ifndef MazePerson_H
#define MazePerson_H


#include <windows.h>
#include <string>
#include "MazeMap.h"

#define WALL 0
#define ROAD 1



class MazePerson
{
public:
	MazePerson(MazeMap* maze);
	void SetPersonInitPos(int x, int y, MazeMap* mazemap);
	void SetPersonSymbol(char symbol);
	void PersonStart();
	void PersonMove(char& Direction);

	/*定义上下左右移动函数*/
	bool MoveUp();
	bool MoveDown();
	bool MoveLeft();
	bool MoveRight();

private:
	int** MapPointer; //定义地图首指针
	COORD Exit_Position;//定义出口坐标

	char Person_Symbol;
	//int Person_Orientation;//设定人物的朝向
	char Peson_Move_Direct;//设定人物的移动方向（由于在屏幕上人物不能旋转，故移动方向和朝向是不一致的，要加以区分）

	int Steps;//记录步数
	COORD CurrentPos;//当前坐标
};


#endif
