#include <iostream>

#include "Map.h"

using namespace std;

void Map::drawmap(int width ,int height)
{
	this->height = height;
	this->width = width;

	int i=0,j=0;
	for (;;)
	{
		if (i == height)
			break;
		if (i==0||i==height-1)
		{
			for (j = 0; j < width; j++)
				cout << "*";
			cout << endl;
			i++;
		}

		else
		{
			cout << "*";
			for (j = 1; j < width - 1; j++)
				cout << " ";
			cout << "*";
			cout << endl;
			i++;
		}
	}
}