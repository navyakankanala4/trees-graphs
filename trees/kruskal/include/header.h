#include<stdlib.h>
#include<stdio.h>
 
#define NIL -1
#define MAX 100
/*structure named edge to store edge,vertex and weight */ 
struct edge
{
      int x;
      int y;
      int weight;
      struct edge *link;
}*front = NULL;
/*function declarations to create a tree,make a graph,insert and traverse in the queue*/ 
void create_tree(struct edge tree[]);
void insert_queue(int i, int j, int wt);
struct edge *traverse();
int isEmpty();
void make_a_graph();
 
int vertices;
