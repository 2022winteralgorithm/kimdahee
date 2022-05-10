#include <stdio.h>

int n, m;
int arr[11];

int main(void)
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        arr[x] += 1;
    }

    int result = 0;
    for (int i = 1; i <= m; i++)
    {
        n -= arr[i];
        result += arr[i] * n;
    }
    printf("%d", result);
}