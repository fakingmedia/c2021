#include <iostream>
#include <ctime>
#include <cmath>
#define MAX 1000000 //之所以设为1000000是因为1000对于clock_tdanwei来说太快而在数值上无法得以体现

int main()
{
    using namespace std;

    clock_t time_start,time_finish;
    bool pri[MAX+1];
    int running = 2;

    pri[0] = pri[1] = false;
    for (int i=2; i<MAX+1; i++)
        pri[i] = true;
    //我们使用Eratosthenes筛法
    time_start = clock(); //计算开始时间
    while (running < sqrt(MAX)+1)
    {
        for (int i=MAX/running; i>=running; i--)
            if (pri[i] == true)
                pri[i*running] = false;
        while (pri[++running] == false)
            ;
    }
    time_finish = clock(); //计算结束时间
    cout << "Here are all the primes beween 2 and " << MAX << ":" << endl;
    for (int i=2; i<MAX+1; i++)
        if (pri[i] == true)
            cout << i << "\t";
    cout << "We had used " << (time_finish - time_start)*1000/CLOCKS_PER_SEC << " ms to process.\n";
    return 0;
}

