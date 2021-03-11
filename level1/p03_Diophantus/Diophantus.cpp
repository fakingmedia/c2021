#include <iostream>

using namespace std;

int main()
{
    int life_father; //父亲和儿子的生命长度必然是整数
    //life_father必然被12，6，7整除
    life_father = 12*7;
    while (life_father != life_father/6 + life_father/12 + life_father/7 + 5 + life_father/2 + 4)
        life_father +=12*7;
    cout << life_father-4;
    return 0;
}
