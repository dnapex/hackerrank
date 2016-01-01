#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minDist(char q[], int dist[], int n);

int main(int argc, char const* argv[])
{
    int t;
    scanf("%d", &t);

    for (int k = 0; k < t; k++) {
        int m, n;
        scanf("%d %d", &n, &m);

        int ** graph = malloc(n*sizeof(int *));
        for (int i = 0; i < n; i++) {
            graph[i] = malloc(n*sizeof(int));
        }

        int const INF = 350*n + 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                graph[i][j] = (i == j) ? 0 : INF;

        for (int i = 0; i < m; i++) {
            int x, y, r;
            scanf("%d %d %d", &x, &y, &r);

            if (graph[--x][--y] && (graph[x][y] < r))
                continue;
            graph[x][y] = graph[y][x] = r;
        }

        int dist[n];
        for (int i = 0; i < n; i++)
            dist[i] = INF;

        int s;
        scanf("%d", &s);
        dist[--s] = 0;

        char q[n];
        memset(q, 1, n);

        do {
            int min = minDist(q, dist, n);

            for (int j = 0; j < n; j++) {
                if (!q[j] || graph[min][j] == INF || graph[min][j] == 0)
                    continue;

                int alt = dist[min]+graph[min][j];
                if (alt < dist[j])
                    dist[j] = alt;
            }
        } while(memchr(q, 1, n));

        for (int i = 0; i < n; i++) {
            if (i == s)
                continue;
            printf("%d ", (dist[i] == INF) ? -1 : dist[i]);
        }

        puts("");
    }

    return 0;
}

int minDist(char q[], int dist[], int n)
{
    int min[2] = {INT_MAX, INT_MAX};

    for (int i = 0; i < n; i++) {
        if (q[i]) {
            if (dist[i] < min[0]) {
                min[0] = dist[i];
                min[1] = i;
            }
        }
    }

    q[min[1]] = 0;
    return min[1];
}

