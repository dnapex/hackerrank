#include <stdio.h>
#include <stdlib.h>


int asc(const void * a, const void * b)
{
        return (*(int*)a - *(int*)b);
}

int main(int argc, char const* argv[])
{
    int n, k;
    scanf("%d %d", &n, &k);

    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    qsort(a, n, sizeof(int), asc);

    int total = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        total += a[i];
        if (total <= k) {
            count++;
        } else {
            break;
        }
    }

    printf("%d\n", count);

    return 0;
}
