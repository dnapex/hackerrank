#include <stdio.h>
#include <stdlib.h>


struct Edge {
    int dst;
    struct Edge * next;
};

struct AdjList {
    struct Edge * head;
};

struct Graph {
    int v;
    struct AdjList * v_list;
};


struct Edge * newEdgeNode(int dst)
{
    struct Edge * newEdge = (struct Edge *) malloc(sizeof(struct Edge));

    newEdge->dst = dst;
    newEdge->next = NULL;

    return newEdge;
}

struct Graph * initGraph(int v)
{
    struct Graph * graph = (struct Graph *) malloc(sizeof(struct Graph));

    graph->v = v;
    graph->v_list = (struct AdjList *) malloc(v*sizeof(struct AdjList));

    for (int i = 0; i < v; i++)
        graph->v_list[i].head = NULL;

    return graph;
}

void addEdge(struct Graph * graph, int src, int dst)
{
    struct Edge * newEdge = newEdgeNode(dst);

    newEdge->next = graph->v_list[src].head;
    graph->v_list[src].head = newEdge;
}


int treeSize(struct Graph * tree, int root, int memoize[])
{
    if (!tree->v_list[root].head)
        return 1;

    if (memoize[root] != 0)
        return memoize[root];

    struct Edge * cursor = tree->v_list[root].head;

    int child = 0;
    while (cursor) {
        child += treeSize(tree, cursor->dst, memoize);
        cursor = cursor->next;
    }

    return child+1;
}

int splitTree(struct Graph * tree, int root, int memoize[])
{
    int forest = 0;
    struct Edge * cursor = tree->v_list[root].head;

    while (cursor) {
        forest += splitTree(tree, cursor->dst, memoize);
        cursor = cursor->next;
    }

    memoize[root] = treeSize(tree, root, memoize);

    if (memoize[root] % 2 == 0)
        forest++;

    return forest;
}

int main(int argc, char const* argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);

    struct Graph * tree = initGraph(n);

    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d %d", &v, &u);

        addEdge(tree, u-1, v-1);
    }

    printf("%d\n", splitTree(tree, 0, malloc(sizeof(int)*n))-1);

    return 0;
}
