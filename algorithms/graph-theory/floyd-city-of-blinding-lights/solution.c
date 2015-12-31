#include <stdio.h>
#include <stdlib.h>

#define INF 100000000

int main(int argc, char const* argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);

    int ** dist = malloc(n*sizeof(int *));
    for (int i = 0; i < n; i++)
        dist[i] = malloc(n*sizeof(int));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = (i == j) ? 0 : INF;

    for (int i = 0; i < m; i++) {
        int x, y, r;
        scanf("%d %d %d", &x, &y, &r);

        dist[--x][--y] = r;
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        printf("%d\n", (dist[--x][--y] == INF) ? -1 : dist[x][y]);
    }

    return 0;
}
