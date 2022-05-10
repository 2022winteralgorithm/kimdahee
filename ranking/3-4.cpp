#include <stdio.h>

int main()
{
    int n, k;
    int result = 0;
    scanf("%d%d", &n, &k);

    while (1)
    {
        int p = n / k; // n이 될 수 있는 가장 큰 k의 배수
        if (p == 0)
            break;
        result += n - p * k;
        n = p;
        result++;
    }

    result += n - 1; // 남은 횟수를 다 더함
    printf("%d", result);
    return 0;
}
