#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

int main()
{
	int location[2] = { 0,4 };
	int maze[10][10] =
	{	{1,1,1,1,0,1,1,1,1,1},	{1,1,1,0,0,1,1,1,1,1},	{1,1,1,0,1,1,1,1,1,1},	{1,1,1,0,1,1,1,0,0,0},
		{1,1,1,0,0,0,0,0,1,0},	{1,1,1,1,1,1,1,0,1,0},	{1,1,1,1,1,1,1,1,0,0},	{1,1,1,1,1,1,1,1,0,1},
		{1,1,1,1,0,0,0,0,0,1},	{1,1,1,1,0,1,1,1,1,1}	};
	int ch1=0;

	while (location[0] != 9)
	{
		system("cls");
		cout << "Q means the wall and y means where you are.\n";
		switch (ch1)
		{
		case 72: 
			printf("The key you Pressed is : ¡ü \n"); 
			if (location[0] != 0 && maze[location[0]-1][location[1]] != 1)
				location[0] -=1; 
			break;
		case 80: 
			printf("The key you Pressed is : ¡ý \n"); 
			if ((location[0] != 9) && (maze[location[0]+1][location[1]] != 1))
				location[0] += 1;
			break;
		case 75: 
			printf("The key you Pressed is : ¡û \n"); 
			if (location[1] != 0 && maze[location[0]][location[1]-1] != 1)
				location[1] -= 1;
			break;
		case 77: 
			printf("The key you Pressed is : ¡ú \n"); 
			if (location[1] != 9 && maze[location[0]][location[1]+1] != 1)
				location[1] += 1;
			break;
		default: printf("No direction keys detected \n"); break;
			break;
		}
		for (int i=0; i<10; i++)
		{
			for (int j = 0; j < 10; j++)
				if (maze[i][j] == 1)
					cout << 'Q';
				else if (location[0] == i && location[1] == j)
					cout << 'y';
				else
					cout << ' ';
			cout << endl;
		}
		ch1 = _getch();
	}
	cout << "Congratulations!" << endl;

	return 0;

}