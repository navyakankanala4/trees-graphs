#include "header.h"
int main()
{
	int n,v,src,dest,ch;
	printf("enter the no of vertices\n");
	scanf("%d",&n);
	struct Graph* graph ;
	while(1)
	{
		printf("enter your choic\n");
		scanf("%d",&ch);
		printf("1.create node\n");
		printf("2.add edge\n");
		printf("3.printgraph");
		printf("4.createGraph\n");
		printf("5.exit\n");
		switch(ch)
		{
			case 1: 
				printf("enter the value of the node to create\n");
				scanf("%d",&v);
				createNode(v);
				break;
			case 2:
				printf("enter the source and desination values\n");
				scanf("%d%d",&src,&dest);
				addEdge(graph,src,dest);
				break;
			case 3:
				printf("elements to be diplayed\n");
				printGraph(graph);
				break;
			case 4:
				printf("enter the v erticx\n");
				scanf("%d",&v);
				createGraph(v);
			case 5:
				exit(0);
				break;
			default:
				printf("mismatch\n");
				break;
		}
	}
}

		

    

