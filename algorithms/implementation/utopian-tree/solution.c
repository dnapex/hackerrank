#include <stdio.h>
#include <stdlib.h>

#define N_MAX 60

int main(int argc, char const* argv[])
{
    int t;
    scanf("%d", &t);

    int * c = (int *) calloc(N_MAX+1, sizeof(int));
    c[0] = 1;
    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);

        if (c[n]) {
            printf("%d\n", c[n]);
        } else {
            int m = n;
            do { m--;} while(!c[m] && m != 0);
            
            int g = 0, h = c[m];
            do { 
                c[m] = h;
                if (m++ % 2 == 0)
                    h *= 2;
                else
                    h++;
            } while (m != n);

            printf("%d\n", h);
        }
    }

    return 0;
}
