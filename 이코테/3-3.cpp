#include <stdio.h>

int main()
{
    int n, m;
    int arr[1000][100] = {
        0,
    };
    int result = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int min = 10001;
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] < min)
            {
                min = arr[i][j];
            }
        }
        if (result < min)
        {
            result = min;
        }
    }
    printf("%d", result);
    return 0;
}