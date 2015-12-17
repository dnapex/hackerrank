#include <stdio.h>

int main(int argc, char const* argv[])
{
    int cases;

    scanf("%d", &cases);

    for (int i = 0; i < cases; i++) {
        int n, k;
        scanf("%d %d", &n, &k);
        
        int present = 0;

        for (int j = 0; j < n; j++) {
            int a;
            scanf("%d", &a);
            if (a <= 0)
                present++;
        }

        printf("%s\n", (present < k) ? "YES" : "NO");
    }

    return 0;
}
