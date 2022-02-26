#include <bits/stdc++.h>
using namespace std;

// 보관 후 하루가 지나면, 익은 토마토들 근처(4방향)에 익지 않은 토마토들이 익음.
// 보관된 토마토들이 며칠이 지나면 익을까, 최소 일수 구하기.

int M, N;
int dXY[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // 4방향
vector<vector<int>> V;                              // 토마토가 심어진 곳
queue<pair<int, int>> Q;                            // 두 객체를 하나의 객체로 취급 할 수 있게 묶는 클래스

void BFS()
{
    while (!Q.empty()) // 큐가 빌 때까지 반복
    {
        pair<int, int> know = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int n = know.first + dXY[i][0]; // 주변(상하좌우) 확인
            int m = know.second + dXY[i][1];

            if (0 <= n && n < N && 0 <= m && m < M && V[n][m] != -1) // 범위 안에 들어오고 토마토 있을 때
            {
                if (V[n][m] == 0 || V[n][m] > V[know.first][know.second] + 1)
                {
                    Q.push(make_pair(n, m));
                    V[n][m] = V[know.first][know.second] + 1; //날짜 증가
                }
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N;

    for (int i = 0; i < N; i++)
    {
        vector<int> tmp;
        for (int j = 0; j < M; j++)
        {
            int x;
            cin >> x;
            tmp.push_back(x);
        }
        V.push_back(tmp);
    }

    for (int i = 0; i < V.size(); i++)
    {
        for (int j = 0; j < V[i].size(); j++)
        {
            if (V[i][j] == 1)            //익은 토마토(1) -> 큐
                Q.push(make_pair(i, j)); // make_pair로 좌표쌍을 큐에 push
        }
    }
    BFS();

    int max = 0;

    for (int i = 0; i < V.size(); i++)
    {
        for (int j = 0; j < V[i].size(); j++)
        {
            if (V[i][j] > max)
                max = V[i][j];
            // 익지 않은 토마토가 존재하면 -1 출력
            if (V[i][j] == 0)
            {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    if (max == 1) // 모든 토마토가 익어있는 상태
        cout << 0 << endl;
    else
        cout << max - 1 << endl; // 최초에 이미 익은 토마토의 배열이 1로 시작해서 -1해주기
}