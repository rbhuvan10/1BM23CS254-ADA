#include <stdio.h>

#define V 5
#define INF 99999  // A large value to represent infinity

int minKey(int key[], int mstSet[]) {
    int min = INF, minIndex;
    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void primMST(int graph[V][V]) {
    int parent[V], key[V];
    int mstSet[V] = {0};

    for (int i = 0; i < V; i++) key[i] = INF;
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("Edge   Weight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d   %d\n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() {
    int graph[V][V];

    printf("Enter the adjacency matrix for the graph (use 0 for no edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("Edge weight between vertex %d and vertex %d: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph);
    return 0;
}

Output:
Enter the adjacency matrix for the graph (use 0 for no edge):
Edge weight between vertex 0 and vertex 0: 4
Edge weight between vertex 0 and vertex 1: 2
Edge weight between vertex 0 and vertex 2: 6
Edge weight between vertex 0 and vertex 3: 0
Edge weight between vertex 0 and vertex 4: 1
Edge weight between vertex 1 and vertex 0: 8
Edge weight between vertex 1 and vertex 1: 3
Edge weight between vertex 1 and vertex 2: 9
Edge weight between vertex 1 and vertex 3: 2
Edge weight between vertex 1 and vertex 4: 7
Edge weight between vertex 2 and vertex 0: 4
Edge weight between vertex 2 and vertex 1: 2
Edge weight between vertex 2 and vertex 2: 7
Edge weight between vertex 2 and vertex 3: 5
Edge weight between vertex 2 and vertex 4: 3
Edge weight between vertex 3 and vertex 0: 5
Edge weight between vertex 3 and vertex 1: 2
Edge weight between vertex 3 and vertex 2: 9
Edge weight between vertex 3 and vertex 3: 0
Edge weight between vertex 3 and vertex 4: 2
Edge weight between vertex 4 and vertex 0: 5
Edge weight between vertex 4 and vertex 1: 7
Edge weight between vertex 4 and vertex 2: 4
Edge weight between vertex 4 and vertex 3: 1
Edge weight between vertex 4 and vertex 4: 9
Edge   Weight
0 - 1   8
4 - 2   3
4 - 3   2
0 - 4   5
