#include <stdio.h>
#include <stdlib.h>

int asc(const void *a, const void * b)
{
    return (*(int*)a - *(int*)b);
}

int dec(const void *a, const void * b)
{
    return (*(int*)b - *(int*)a);
}

int main(int argc, char const* argv[])
{
    int t;

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n, k;
        scanf("%d %d", &n, &k);

        int a[n], b[n];

        for (int j = 0; j < n; j++) {
            scanf("%d", &a[j]);
        }
        for (int j = 0; j < n; j++) {
            scanf("%d", &b[j]);
        }

        qsort(a, n, sizeof(int), asc);
        qsort(b, n, sizeof(int), dec);

        int possible = 1;

        for (int j = 0; j < n; j++) {
            if (a[j]+b[j] < k) {
                possible = 0;
            }
        }

        printf("%s\n", possible ? "YES" : "NO");
    }

    return 0;
}
