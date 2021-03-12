#include <iostream>
#define NUM 64
using namespace std;
void hanoi(int num, long long* times, int a[], int from, int to);//把靠上的num个圆盘从from移动到to
int left(int one, int another);//找到并返回1，2，3中没有出现在one和another中的一个

int main()
{
    int a[NUM+1];//表示从小到大第N个圆盘的位置
    long long times=0;//操作次数
    for (int i = 0; i<NUM+1; i++)
        a[i] = 1;//初始位置均在第1根柱子上
    hanoi(NUM, &times, a, 1, 3);
    cout << "There are " << times << " steps to move all the discs." << endl;
    return 0;
}

int left(int one, int another)
{
    if (1<one && 1<another)
        return 1;
    else if (3>one &3>another)
        return 3;
    else
        return 2;
}

void hanoi(int num, long long* times, int a[], int from, int to)
{
    if (num > 0)
    {
        hanoi(num-1, times, a, from, left(from, to));
        *times += 1;
        cout << "step " << *times << " :Move disc " << num <<
        " from perestele "<< a[num] << " to perestele "<< to << endl;
        a[num] = to;
        hanoi(num-1, times, a, left(from, to), to);
    }
}