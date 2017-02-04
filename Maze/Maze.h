#ifndef MazeMap_H
#define MazeMap_H

#include <windows.h>

using namespace std;

#define WALL 0
#define ROAD 1



class MazeMap
{
public:
	//MazeMap();
	~MazeMap();

	void SetMap(int *Map, int rows, int cols);
	void SetSymbol(char Wall_Symbol, char Road_Symbol); // 设置代表墙的字符
	void DrawMap(); // 打印地图
	int** GetMapPointer();	//获取地图二维数组的指针
	int GetMapRows();
	int GetMapCols();
	void Set_Exit_Position(int x, int y);	//设置出口位置
	COORD Get_Exit_Positon();	//获取出口位置


private:
	char Wall_Symbol;	 //代表墙的字符
	char Road_Symbol;	 //代表路的字符
	int m_rows, m_cols;  //二维数组的行数、列数
	int** MapPointer;    //定义地图首指针
	COORD Exit_Position; //定义出口坐标
};



#endif
