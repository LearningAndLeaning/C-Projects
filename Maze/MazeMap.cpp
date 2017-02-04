#include "MazeMap.h"
#include <iostream>

using namespace std;

//设置地图
void MazeMap::SetMap(int *Map, int rows, int cols)
{
	this->m_cols = cols;
	this->m_rows = rows;

	/*二维指针构建二维数组的方法*/
	MapPointer = new int*[m_rows];
	for (int i = 0; i < m_rows; i++)
		MapPointer[i] = new int[m_cols];

	/*初始化地图（二维数组），将二维数组看成一维数组来处理*/
	int *p = Map;
	for (int i = 0; i < m_rows; i++)
	for (int j = 0; j < m_cols; j++)
	{
		MapPointer[i][j] = *p;
		p++;
	}
}

COORD MazeMap::Get_Exit_Positon()
{
	return Exit_Position;
}

void MazeMap::Set_Exit_Position(int x,int y)
{
	Exit_Position.X = x;
	Exit_Position.Y = y;

}

void MazeMap::SetSymbol(char Wall_Symbol, char Road_Symbol)
{
	this->Wall_Symbol = Wall_Symbol;
	this->Road_Symbol = Road_Symbol;
}

void MazeMap::DrawMap()
{
	int n = 1;//用来标记每行最多显示多少个字符
	for (int i = 0; i < m_rows;i++)
	for (int j = 0; j < m_cols; j++)
	{
		if (n <= 11)
		{
			if (MapPointer[i][j] == 1)
			{
				cout << Road_Symbol;
				n++;
			}
			if (MapPointer[i][j] == 0)
			{
				cout << Wall_Symbol;
				n++;
			}
		}
		else
		{
			cout << endl;
			n = 1;
			if (MapPointer[i][j] == 1)
			{
				cout << Road_Symbol;
				n++;
			}
			if (MapPointer[i][j] == 0)
			{
				cout << Wall_Symbol;
				n++;
			}

		}
	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
}

int** MazeMap::GetMapPointer()
{
	return MapPointer;
}

int MazeMap::GetMapRows()
{
	return m_rows;
}

int MazeMap::GetMapCols()
{
	return m_cols;
}


//析构函数
//由于存储地图数据的二维数组是动态申请的内存空间，所以要在析构函数中进行释放
MazeMap::~MazeMap()
{
	if (MapPointer)
	{
		for (int i = 0; i < m_rows; i++)
		{
			delete []MapPointer[i];
			MapPointer[i] = NULL;
		}
		delete MapPointer;
		cout << "~MazeMap()" << endl;

		system("pause");
	}
}
