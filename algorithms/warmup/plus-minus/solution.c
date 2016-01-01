#include <stdio.h>

int main(int argc, char const* argv[])
{
    int n;
    scanf("%d", &n);

    int z = 0, p = 0, m = 0;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);

        (a == 0) ? z++ : (a > 0) ? p++ : m++; 
    }

    printf("%.6f\n%.6f\n%.6f", (float)p/n, (float)m/n, (float)z/n);

    return 0;
}
