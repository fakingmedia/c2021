#include <iostream>

int cube(int n);

int main()
{
    using namespace std;
    cout << "Narcissus number between 100 and 999 are as follows:\n";
    //因为10的三次方为1000，故三个立方数的底数只能为1，2，...9
    for (int i = 1; i < 10; i++)
        for (int j = 1; j < 10; j++)
            for (int k = 1; k < 10; k++)
                if ((100*i+10*j+k) == (cube(i)+cube(j)+cube(k)))
                    cout << 100*i+10*j+k << endl;
    return 0;
}

int cube(int n)
{
    return n*n*n;
}