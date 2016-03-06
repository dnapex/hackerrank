#include <stdio.h>
#include <stdlib.h>

int boyer(int a[], int s)
{
    int n = a[0], c = 0;
    for (int i = 0; i < s; i++) {
        if (n == a[i]) {
            ++c;
        } else if (c == 0) {
            n = a[i];
            ++c;
        } else {
            --c;
        }
    }

    return n;
}

int asc(const void * a, const void * b)
{
    return (*(int *)a - *(int *)b);
}

int main(int argc, char const* argv[])
{
    char s[100000];
    scanf("%s", s);

    int * c = (int *) calloc(26, sizeof(int));
    for (char * i = s; *i != 0; i++) {
        c[*i%26]++;
    }

    qsort(c, 26, sizeof(int), asc);

    int i = 0;
    int * a = c;
    while (*a == 0) {
        a++; i++;
    }

    int d = 0, m = boyer(a, 26-i);
    for (int j = i; (j < 26) && (d <= 1); j++)
        d += abs(c[j]-m);

    if (d > 1) {
        d = 0;
        for (int j = i, k = 0; j < 26; j++) {
            if (c[j] == 1) {
                k++;
                continue;
            }
            if ((k > 1) || (c[j] != m)) {
                d = 2;
                break;
            }
        }
    }

    printf("%s\n", (d <= 1) ? "YES" : "NO");

    return 0;
}
