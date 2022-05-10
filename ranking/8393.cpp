#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    int N, sum = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        sum += i + 1;
    }
    cout << sum;
    return 0;
}