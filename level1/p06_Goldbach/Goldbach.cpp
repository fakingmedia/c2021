#include <iostream>
#include <cmath>
#define MAX 100 //用上一题的代码

int main()
{
    using namespace std;

    bool pri[MAX+1];
    int running = 2;

    pri[0] = pri[1] = false;
    for (int i=2; i<MAX+1; i++)
        pri[i] = true;
    //我们使用Eratosthenes筛法
    while (running < sqrt(MAX)+1)
    {
        for (int i=MAX/running; i>=running; i--)
            if (pri[i] == true)
                pri[i*running] = false;
        while (pri[++running] == false)
            ;
    }
    for (int i=4; i<MAX+1; i+=2)
    {
        for (int j=2; j<=i/2; j++)
        {
            if ((pri[j]==true) && (pri[i-j]==true))
            {
                cout << "Odd " << i << " is the addition of " << j << " and " << i-j <<endl;
                break;
            }

        }
    }


    return 0;
}

