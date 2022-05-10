#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> food_times, long long k)
{
    int answer = 0;
    long long sum = 0;
    int left = food_times.size(); // 남은 음식의 개수
    int prev = 0;                 // 이전 음식 개수

    for (int i = 0; i < left; i++){
        sum += food_times[i];
    }
    // 더 섭취해야 할 음식이 없다면 -1 반환
    if (sum <= k)
    {
        return -1;
    }

    // 음식 time 과 index를 우선순위 큐에 저장
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < food_times.size(); i++)
    {
        pq.push(make_pair(-food_times[i], i + 1)); // 최소 힙을 사용해서 음식 시간 작은 순으로
    }

    while (1)
    {
        pair<int, int> top = pq.top();
        if ((-top.first - prev) * left > k) // 더 이상 돌지 못하는 경우
        {
            break;
        }
        k -= (-top.first - prev) * left;
        prev = -top.first;
        pq.pop();
        left--;
    }

    // 남은 음식 인덱스 정렬
    vector<int> remains;
    // 큐가 빌 때까지 진행
    while (!pq.empty())
    {
        int idx = pq.top().second;
        remains.push_back(idx);
        pq.pop();
    }
    // 남은 음식 번호순으로 정렬
    sort(remains.begin(), remains.end());

    answer = remains[int(k % remains.size())];

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> food_times;
    for (int i = 0; i < n; i++)
    {
        int time;
        cin >> time;
        food_times.push_back(time);
    }

    long long k;
    cin >> k;

    cout << solution(food_times, k) << '\n';

    return 0;
}