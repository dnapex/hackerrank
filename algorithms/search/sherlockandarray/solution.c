#include <stdio.h>

int eqsearch(int a[], int n, int low, int high)
{
    if (low > high) {
        printf("NO\n");
        return 0;
    }

    int mid = (low+high) / 2;

    int left = 0;
    for (int i = 0; i < mid; i++) {
        left += a[i];
    }

    int right = 0;
    for (int i = n-1; i > mid; i--) {
        right += a[i];
    }

    if (left == right) {
        printf("YES\n");
        return 0;
    }
    
    if (left > right) {
        eqsearch(a, n, low, mid-1);
    } else {
        eqsearch(a, n, mid+1, high);
    }

    return -1;
}

int main(int argc, char const* argv[])
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);

        int a[n];
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[j]);
        }

        eqsearch(a, n, 0, n-1);
    }
    return 0;
}
