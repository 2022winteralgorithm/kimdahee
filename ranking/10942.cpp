#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int arr[2001];
bool palindrom[2001][2001] = {
    false,
};

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n, m, s, e;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    cin >> m;

    for (int i = 1; i <= n; i++) // 길이가 1일 때
    {
        palindrom[i][i] = true;
    }

    for (int i = 1; i <= n - 1; i++) // 길이가 2일 때
    {
        if (arr[i] == arr[i + 1])
            palindrom[i][i + 1] = true;
    }

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 2; j <= n; j++) // 길이가 3이상일 때
        {
            if (arr[i] == arr[j] && palindrom[i + 1][j - 1] == true)
            {
                palindrom[i][j] = true;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        cin >> s >> e;
        cout << palindrom[s][e]
             << '\n';
    }

    return 0;
}