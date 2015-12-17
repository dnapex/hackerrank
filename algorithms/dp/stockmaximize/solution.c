#include <stdio.h>

int main(int argc, char const* argv[])
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);

        int a[n];
        for (int j = 0; j < n; j++)
            scanf("%d", &a[j]);

        int max = 0;
        long profit = 0;

        for (int j = n-1; j >=0; j--) {
            if (max < a[j])
                max = a[j];
            profit += (max - a[j]);
        }

        printf("%d\n", profit);
    }

    return 0;
}
