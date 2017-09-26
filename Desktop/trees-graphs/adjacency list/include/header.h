#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int vertex;
    struct node* next;
};
struct node* createNode(int);

struct Graph
{
    int numVertices;
    struct node** adjLists;
};

struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);

