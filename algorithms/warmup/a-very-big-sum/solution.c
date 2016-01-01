#include <stdio.h>

int main(int argc, char const* argv[])
{
    int n;
    scanf("%d", &n);

    long long int total = 0;
    for (int i = 0; i < n; i++) {
        long long int a;
        scanf("%lld", &a);
        total += a;
    }

    printf("%lld", total);

    return 0;
}
