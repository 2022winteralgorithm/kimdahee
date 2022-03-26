#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v;
    int n, m, k, result = 0;
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    int first = v[n - 1];
    int second = v[n - 2];

    result = first * k * (m / k) + second * (m % k);
    printf("%d", result);
    return 0;
}