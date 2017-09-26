#include "header.h"
/*function to create node*/
struct node* createNode(int v)
{
	struct node* newNode = malloc(sizeof(struct node));
    	newNode->vertex = v;
    	newNode->next = NULL;
    	return newNode;
}
 
/*function to create graph*/
struct Graph* createGraph(int vertices)
{
	struct Graph* graph = malloc(sizeof(struct Graph));
    	graph->numVertices = vertices;
 
    	graph->adjLists = malloc(vertices * sizeof(struct node*));
 
    	int i;
    	for (i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;
 
    	return graph;
}
 /*function to add an edge*/
void addEdge(struct Graph* graph, int src, int dest)
{
    	/* Add edge from src to dest*/
    	struct node* newNode = createNode(dest);
    	newNode->next = graph->adjLists[src];
    	graph->adjLists[src] = newNode;
 
    	/*Add edge from dest to src*/
    	newNode = createNode(src);
    	newNode->next = graph->adjLists[dest];
    	graph->adjLists[dest] = newNode;
}
/*function to printgraph*/ 
void printGraph(struct Graph* graph)
{
    	int v;
    	for (v = 0; v < graph->numVertices; v++)
    	{
        	struct node* temp = graph->adjLists[v];
        	printf("\n Adjacency list of vertex %d\n ", v);
        	while (temp)
        	{
            		printf("%d -> ", temp->vertex);
            		temp = temp->next;
        	}
        	printf("\n");
    	}
}
