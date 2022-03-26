#include <stdio.h>

int main()
{
    int n, k;
    int result = 0;
    scanf("%d%d", &n, &k);

    while (1)
    {
        if (n % k == 0)
        {
            n /= k;
        }
        else
        {
            n -= 1;
        }
        result++;
        if (n == 1)
            break;
    }

    printf("%d", result);
    return 0;
}