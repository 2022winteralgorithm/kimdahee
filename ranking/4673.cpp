#include <iostream>

using namespace std;
bool arr[10001];

int d(int n)
{
    int sum = n;

    while (true)
    {
        if (n == 0)
            break;
        sum += n % 10;
        n = n / 10;
    }

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    for (int i = 1; i <= 10000; i++)
    {
        int tmp = d(i);
        if (tmp <= 10000)
        {
            arr[tmp] = true;
        }
    }

    for (int i = 1; i <= 10000; i++)
    {
        if (!arr[i])
        {
            cout << i << "\n";
        }
    }

    return 0;
}