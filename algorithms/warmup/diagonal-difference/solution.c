#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const* argv[])
{
    int n;
    scanf("%d", &n);

    int a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    int d = 0;
    for (int i = 0, j = n-1; i < n; i++, j--)
        d = d + (a[i][i] - a[i][j]);

    printf("%d", abs(d));

    return 0;
}
