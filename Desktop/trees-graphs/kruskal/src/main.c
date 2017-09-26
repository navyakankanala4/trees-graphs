#include "header.h"
int vertices;
 
int main()
{
	int count;
      	struct edge tree[MAX];
      	int tree_weight = 0;
	/*initially make a graph */
      	make_a_graph();
	/*now reate a tree*/
      	create_tree(tree);
      	printf("Edges in MST:\n");
	/*check whether the count is less than number of vertices or not*/
      	for(count = 1; count <= vertices - 1; count++)
      	{
		/*print the info of edge vertex and weight*/
            	printf("%d->", tree[count].x);
            	printf("%d\n", tree[count].y);
            	tree_weight = tree_weight + tree[count].weight;
      	}
      	printf("Total Weight of this Minimum Spanning Tree:\t%d\n", tree_weight);
      	return 0;
}
