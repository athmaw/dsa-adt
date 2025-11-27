#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 9
#define VISITED -1
#define UNVISITED 100

typedef int vertex;

typedef struct node {
    int elem;
    struct node *link;
} *ptr, Node;

typedef ptr Graph[MAX];

void initGraph(Graph G) {
    for (int i = 0; i < MAX; i++) {
        G[i] = NULL;
    }
}

void addEdge(Graph G, vertex src, vertex dest) {
    ptr newNode = (ptr)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    newNode->elem = dest;
    newNode->link = G[src];
    G[src] = newNode;
}

void dfs(Graph G, vertex v, int mark[]) {
    ptr trav = G[v];
    mark[v] = VISITED;
    printf("%d ", v);

    while (trav != NULL) {
        if (mark[trav->elem] == UNVISITED) {
            dfs(G, trav->elem, mark);
        }
        trav = trav->link;
    }
}

void bfs(Graph G, vertex start, int mark[]) {
    int queue[MAX];
    int front = 0, rear = 0;

    mark[start] = VISITED;
    queue[rear++] = start;

    while (front < rear) {
        vertex v = queue[front++];
        printf("%d ", v);

        for (ptr trav = G[v]; trav != NULL; trav = trav->link) {
            vertex u = trav->elem;
            if (mark[u] == UNVISITED) {
                mark[u] = VISITED;
                queue[rear++] = u;
            }
        }
    }
}

int main(void) {
    Graph G;
    int mark[MAX];

    initGraph(G);
    for (int i = 0; i < MAX; i++) {
        mark[i] = UNVISITED;
    }

    /* build an undirected sample graph */
    addEdge(G, 0, 1); addEdge(G, 1, 0);
    addEdge(G, 0, 2); addEdge(G, 2, 0);
    addEdge(G, 1, 3); addEdge(G, 3, 1);
    addEdge(G, 1, 4); addEdge(G, 4, 1);
    addEdge(G, 2, 5); addEdge(G, 5, 2);
    addEdge(G, 5, 6); addEdge(G, 6, 5);

    printf("DFS traversal starting at 0:\n");
    dfs(G, 0, mark);
    printf("\n\n");

    /* reset marks for BFS */
    for (int i = 0; i < MAX; i++) {
        mark[i] = UNVISITED;
    }

    printf("BFS traversal starting at 0:\n");
    bfs(G, 0, mark);
    printf("\n");

    return 0;
}
