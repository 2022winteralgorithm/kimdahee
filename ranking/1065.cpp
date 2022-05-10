#include <iostream>
using namespace std;

bool han(int n);

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (han(i) == true)
            cnt += 1;
    }
    cout << cnt;

    return 0;
}

bool han(int n)
{
    int hun = n / 100;
    int ten = (n / 10) % 10;
    int one = n % 10;

    if (n < 100 || (hun - ten) == (ten - one))
        return true;
    else
        return false;
}