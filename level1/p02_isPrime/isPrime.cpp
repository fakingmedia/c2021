#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int pri,sqr;
    int n = 1;
    cin >> pri;
    sqr = floor(sqrt(pri));
    for (int i = 2; i <= sqr; i++)
        if (pri % i == 0)
        {
            n = 0;
            break;
        }
    if (1 == n)
        cout << "It is a prime!" << endl;
    else
        cout << "It is not a prime!" << endl;

    return 0;
}
