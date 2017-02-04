#include <stdlib.h>
#include <iostream>
#include "MazeMap.h"
#include "MazePerson.h"

/*---------------------------------------------------------------------------------------------------------------------------------------*/
/*
	这是一个“走出迷宫”的模拟动画 

	1.画出这个迷宫：由于我们画的二维空间的迷宫，所以用一个二维数组存储代表墙和路的字符就OK了，这里我们用字符’H’代表墙，用空格符代表路。
	2.定义一个走迷宫的人person：person是我们的游戏角色，显示上我们将用字符’！’来表示，person可以向各个方向移动。
	3.person走迷宫的原则（左手原则）：优先向左走，其次向前走，再次向右走，若三个方向均无路，则掉头向后走。

			
												DATA: 2017.2.4 21:46        by: Sildust

*/
/*---------------------------------------------------------------------------------------------------------------------------------------*/

int main()
{
	//定义并初始化存储地图数据的二维数组
	int Map[11][11] = {
		{ WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL },
		{ WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD },
		{ WALL, ROAD, WALL, WALL, WALL, ROAD, WALL, WALL, WALL, ROAD, WALL },
		{ WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, WALL, ROAD, WALL },
		{ WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, WALL, WALL },
		{ WALL, ROAD, WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, WALL },
		{ WALL, ROAD, WALL, WALL, WALL, WALL, WALL, WALL, WALL, ROAD, WALL },
		{ WALL, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, WALL, ROAD, WALL },
		{ WALL, WALL, WALL, ROAD, WALL, WALL, WALL, ROAD, WALL, ROAD, WALL },
		{ ROAD, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, WALL },
		{ WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL }
	};

	MazeMap *mazemap = new MazeMap;;
	mazemap->SetMap(&Map[0][0],11,11);
	mazemap->SetSymbol('H', ' ');
	mazemap->Set_Exit_Position(10, 1);
	mazemap->DrawMap();

	MazePerson *person = new MazePerson(mazemap);
	person->SetPersonSymbol('!');
	person->SetPersonInitPos(0,9, mazemap);

	person->PersonStart();
	
	
	delete mazemap;
	delete person;

	system("pause");
}
