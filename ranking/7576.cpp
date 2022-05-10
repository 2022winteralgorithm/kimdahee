#include <bits/stdc++.h>
using namespace std;

int N, M;
int xy[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<vector<int>> Tomato;
queue<pair<int, int>> Q;

void solve()
{
    while (!Q.empty())
    {
        pair<int, int> know = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int n = know.first + xy[i][0];
            int m = know.second + xy[i][1];

            if (0 <= n && n < N && 0 <= m && m < M && Tomato[n][m] != -1)
            {
                if (Tomato[n][m] == 0 || Tomato[n][m] > Tomato[know.first][know.second] + 1)
                {
                    Q.push(make_pair(n, m));
                    Tomato[n][m] = Tomato[know.first][know.second] + 1;
                }
            }
        }
    }
}

int main()
{
    cin >> M >> N;
    for (int i = 0; i < N; i++)
    {
        vector<int> temp;
        for (int j = 0; j < M; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        Tomato.push_back(temp);
    }

    for (int i = 0; i < Tomato.size(); i++)
    {
        for (int j = 0; j < Tomato.size(); j++)
        {
            if (Tomato[i][j] == 1)
                Q.push(make_pair(i, j));
        }
    }

    solve();

    int max = 0;
    for (int i = 0; i < Tomato.size(); i++)
    {
        for (int j = 0; j < Tomato.size(); j++)
        {
            if (Tomato[i][j] > max)
                max = Tomato[i][j];
            if (Tomato[i][j] == 0)
            {
                cout << -1;
                return 0;
            }
        }
    }

    if (max == 1)
        cout << 0;
    else
        cout << max - 1;
}