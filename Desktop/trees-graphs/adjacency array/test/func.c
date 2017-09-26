#include "header.h"
/*creation of graph*/
void create_graph()
{
	int i,max,source,dest;
	/*maximum number of nodes are denoted as max*/
	max=n*(n-1);
	for(i=0;i<max;i++)
	{
		printf("enter source and destination\n");
		scanf("%d%d",&source,&dest);
		/*if the source and dest is -1 then it comes out of the loop*/
		if((source==-1)&&(dest==-1))
		break;
		/*if the source an destination values are <0 or >=n it is invalid*/
		if((source>=n)||(dest>=n)||(source<0)||(dest<0))
		{
			printf("invalid\n");
			i--;
		}
		else
		adj[source][dest]=1;
	}
}
/*inserrtion of edge*/
void insert_edge(int source,int dest)
{
	if((source<0)&&(source>=n))
	{
		printf("vertex invalid\n");
	}
	if((dest<0)&&(dest>=n))
	{
		printf("dest vertex invalid\n");
		return ;
	}
	adj[source][dest]=1;
}
/*deletion of edge*/
void del_edge(int source,int dest)
{
	if((source<0)||(source>=n)||(dest<0)||(dest>=n)||(adj[source][dest]==0))
	printf("edge cannot be deleted\n");
	adj[source][dest]=0;
}
/*display*/
void display()
{
	
	int i,j;
	for(i=0;i<n;i++)
	{
		
		for(j=0;j<n;j++)
		printf("%4d",adj[i][j]);
		
		printf("\n");
			
	}

	
	
}
