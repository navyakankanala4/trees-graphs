#include "header.h"
int main()
{
	int ch,source,dest;
	printf("enter number of vertices\n");
	scanf("%d",&n);
	create_graph();
	while(1)
	{
		printf("1.insert an edge\n");
		printf("2.delete an edge\n");
		printf("3.display\n");
		printf("4.exit\n");
		printf("\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter an edge to be inserted\n");
				scanf("%d%d\n",&source,&dest);
				insert_edge( source, dest);
				break;
			case 2:
				printf("enter an edge to delete\n");
				scanf("%d%d",&source,&dest);
				del_edge(source, dest);
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("mismatch\n");
				break;
		}
	}
 return 0;
}
