#include <iostream>
using namespace std;

int main()
{
    int money[] = {500, 100, 50, 10};
    int n = 1260, cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        cnt += n / money[i];
        n %= money[i];
    }

    cout << cnt;
    return 0;
}