#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int u, v, weight;
} Edge;


typedef struct {
    int parent;
    int rank;
} Subset;


int compareEdges(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}


int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}


void unionSets(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}


void kruskal(Edge edges[], int V, int E) {
    Edge result[V];  
    int e = 0;  
    int i = 0;  

    
    qsort(edges, E, sizeof(edges[0]), compareEdges);

   
    Subset *subsets = (Subset *)malloc(V * sizeof(Subset));

    
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

   
    while (e < V - 1 && i < E) {
        Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.u);
        int y = find(subsets, nextEdge.v);

        
        if (x != y) {
            result[e++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

 
    printf("Edges in the Minimum Spanning Tree:\n");
    int mstWeight = 0;
    for (i = 0; i < e; i++) {
        printf("%d -- %d == %d\n", result[i].u, result[i].v, result[i].weight);
        mstWeight += result[i].weight;
    }
    printf("Weight of MST: %d\n", mstWeight);

    free(subsets);
}


int main() {
    int V, E;

    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);

  
    Edge *edges = (Edge *)malloc(E * sizeof(Edge));

    printf("Enter each edge in the form u v weight:\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }


    kruskal(edges, V, E);

    
    free(edges);

    return 0;
}
Output:
Enter the number of vertices and edges: 4 5
Enter each edge in the form u v weight:
0 1 10
0 2 6
0 3 5 
1 3 15
2 3 4
Edges in the Minimum Spanning Tree:
2 -- 3 == 4
0 -- 3 == 5
0 -- 1 == 10
Weight of MST: 19
