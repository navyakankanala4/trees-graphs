#include "header.h"
/*function to create a tree*/
void create_tree(struct edge tree[])
{
      struct edge *tmp;
      int y1, y2, root_y1, root_y2;
      int parent[MAX];
      int i, count = 0;
      for(i = 0; i < vertices; i++)
      {
            parent[i] = NIL;
      }
	/*if the graph is empty and vertices is n-1*/
	while(!isEmpty( ) && count < vertices - 1) 
      	{
		/*traverse queue*/
		tmp = traverse();
		/*storing vertex*/
            	y1 = tmp->x; 
		/*storing edge*/
            	y2 = tmp->y; 
            	while(y1 != NIL)
           	{
          		root_y1 = y1;
                  	y1 = parent[y1];
            	}
            		while(y2 != NIL)
            		{
                  		root_y2 = y2;
                  		y2 = parent[y2];
            		}
			/*if both roots are not same*/
            		if(root_y1 != root_y2)
            		{
				/*increase count and store edge,vertex and weight values in tree array*/
                  		count++;
                  		tree[count].x = tmp->x;
                  		tree[count].y = tmp->y;
                  		tree[count].weight = tmp->weight;
                  		parent[root_y2] = root_y1;
            		}
      	}
	/*if number of vertices is less printf graph is disconnected*/
	if(count < vertices - 1)
      	{
        	printf("Graph is Disconnected. Therefore, Spanning Tree is not possible\n");
            	exit(1);
      	}
}
/*function to insert node into queue*/
void insert_queue(int i, int j, int wt)
{
	struct edge *tmp, *q;
      	tmp = (struct edge *)malloc(sizeof(struct edge));
	/*vertex*/
      	tmp->x = i;
	/*edge*/
      	tmp->y = j;
	/*weight*/
      	tmp->weight = wt;
	/*if front is NULL and weight is less than temp weight then insert node*/
      	if(front == NULL || tmp->weight < front->weight)
      	{
        	tmp->link = front;
            	front = tmp;
      	}
        else
      	{
		/*else store front in temp varaible  and check if it is empty and weight is less than the element existing and traverse*/
            	q = front;
            	while(q->link != NULL && q->link->weight <= tmp->weight)
            	{
                	q = q->link;
            	}
		
            	tmp->link = q->link;
            	q->link = tmp;
            	if(q->link == NULL) 
            	{
                  	tmp->link = NULL;
            	}
      	}
}
 /*function to traverse*/
struct edge *traverse()
{
	struct edge *tmp;
	/*storing the value of front in temp*/
      	tmp = front;
      	front = front->link;//pointing front to next 
      	return tmp;
}
 /*empty function*/
int isEmpty()
{
	if(front == NULL)
      	{
            	return 1;
      	}
      	else
      	{
            	return 0;
      }
}
 /*function to make a graph*/
void make_a_graph()
{
	/*variables to store weight,max no of nodes,origin and destinations*/
	int count, weight, maximum_edges, origin_vertex, destination_vertex;
      	printf("Enter Total Number of Vertices:\t");
      	scanf("%d", &vertices);
	/*max number of vertices=(no of vertices)*(no of vertices-1)/2*/
      	maximum_edges = vertices * (vertices - 1)/2;
	/*check whether the count is  less than the maximum number of vertices*/
      	for(count = 0; count < maximum_edges; count++)
      	{
            	printf("Enter Edge [%d] Co-ordinates [-1 -1] to Quit\n", count + 1);
            	printf("Enter Origin Point:\t"); 
            	scanf("%d", &origin_vertex);
            	printf("Enter Destination Point:\t");
            	scanf("%d", &destination_vertex);
            	if((origin_vertex == -1) && (destination_vertex == -1))
            	{
                  	break;
            	}
            	printf("Enter Weight for this Edge:\n");
            	scanf("%d", &weight);
		/*origin and destination values shuld be in the range of 0 to no.of vertices*/
            	if(origin_vertex >= vertices || destination_vertex >= vertices || origin_vertex < 0 || destination_vertex < 0)
            	{
                  	printf("Entered Edge Co - ordinates is Invalid\n");
                  	count--;
            	}
		/* if not insert a node*/
            	else
            	{
                  	insert_queue(origin_vertex, destination_vertex, weight);
            	}
      	}
}
