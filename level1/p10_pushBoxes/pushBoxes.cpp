#include<iostream>
#include <conio.h>
#define MAXSCORE 300
using namespace std;
//设定：箱子推到目的地后变成一格的墙，不能同时推动两个箱子
int main()
{
    FILE* fp;
    for (int i = 1; i <= 3; i++)
    {
        //读取文件信息(第一行输入迷宫大小（长宽），后面输入迷宫，用逗号隔开，最后一行输入人的初始位置)
        switch (i)
        {
            case 1:
                fp = fopen("level1.txt","r");
                break;
            case 2:
                fp = fopen("level2.txt", "r");
                break;
            case 3:
                fp = fopen("level3.txt", "r");
                break;
            default:
                break;
        }
        int row, column;
        int x, y;//人的位置
        fscanf(fp, "%d%d", &row, &column);
        int maze[row][column];
        for (int j=0; j<row; j++)
            for (int k=0; k<column; k++)
                fscanf(fp, "%d", &maze[j][k]);//0是空白，1是墙，2是箱子，3是箱子的目标,4是人
        fscanf(fp, "%d%d",&x,&y);
        x -= 1;
        y -= 1;
        if (fclose(fp) != 0)
            fprintf(stderr, "Error in closing the file\n");
        //cmd上推箱子
        int score = MAXSCORE;
        bool win = false;
        int ch;
        while (1)
        {
            score--;
            system("cls");
            maze[x][y] = 4;
            for (int j=0; j<row; j++)
            {
                for (int k=0; k<column; k++)
                    switch(maze[j][k])
                    {
                        case 0:
                            printf(" ");
                            break;
                        case 1:
                            printf("Q");
                            break;
                        case 2:
                            printf("X");
                            break;
                        case 3:
                            printf("M");
                            break;
                        case 4:
                            printf("p");
                            break;
                        default:
                            break;
                    }
                printf("\n");
            }
            maze[x][y] = 0;
            if (win == true)
                break;
            ch = _getch();
            switch(ch)
            {
                case 75:
                    if (y > 0 && (maze[x][y-1] == 0 || (maze[x][y-1] == 2 && y > 1 && maze[x][y-2] != 2 && maze[x][y-2] != 1)))
                    {
                        if (maze[x][y-1] == 2)
                        {
                            maze[x][y-1] = 0;
                            if (maze[x][y-2] == 3)
                                maze[x][y-2] = 1;
                            else
                                maze[x][y-2] = 2;
                        }
                        y -= 1;
                    }
                    break;
                case 77:
                    if (y < row-1 && (maze[x][y+1] == 0 || (maze[x][y+1] == 2 && y < row-2 && maze[x][y+2] != 2 && maze[x][y+2] != 1)))
                    {
                        if (maze[x][y+1] == 2)
                        {
                            maze[x][y+1] = 0;
                            if (maze[x][y+2] == 3)
                                maze[x][y+2] = 1;
                            else
                                maze[x][y+2] = 2;
                        }
                        y += 1;
                    }
                    break;
                case 72:
                    if (x > 0 && (maze[x-1][y] == 0 || (maze[x-1][y] == 2 && x > 1 && maze[x-2][y] != 2 && maze[x-2][y] != 1)))
                    {
                        if (maze[x-1][y] == 2)
                        {
                            maze[x-1][y] = 0;
                            if (maze[x-2][y] == 3)
                                maze[x-2][y] = 1;
                            else
                                maze[x-2][y] = 2;
                        }
                        x -= 1;
                    }
                    break;
                case 80:
                    if (x < column-1 && (maze[x+1][y] == 0 || (maze[x+1][y] == 2 && x<column-2 && maze[x+2][y] != 2 && maze[x+2][y] != 1)))
                    {
                        if (maze[x+1][y] == 2)
                        {
                            maze[x+1][y] = 0;
                            if (maze[x+2][y] == 3)
                                maze[x+2][y] = 1;
                            else
                                maze[x+2][y] = 2;
                        }
                        x += 1;
                    }
                    break;
                default:
                    break;
            }
            win = true;
            for (int j=0; j<row; j++)
                for (int k=0; k<column; k++)
                    if (maze[j][k] == 2)
                        win = false;
        }
        printf("You win!\n");
        //文件输出分数
        fp = fopen("score.txt","w");
        fprintf(fp, "Your score for level%d is %d\n", i, score);
        if (fclose(fp) != 0)
            fprintf(stderr, "Error in closing the file\n");
    }

    return 0;
}
