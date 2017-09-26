#include "header.h"
int main()
{
	struct node *root=NULL;
	int ch;
	int value,a,b;
	
	while(1)
	{
		printf("1.insert\n 2.preorder\n 3.inorder\n 4.postorder\n5.balance_factor\n6.height\n7.delete\n 8.exit\n ");
	scanf("%d",&ch);
		switch(ch)
		{
			case 1: 	
				printf("enter the value whicch is to be inserted into the actual tree\n");
				scanf("%d",&value);
				insert(root,value);
				break;
			case 2:
				printf("preorder\n");
				preorder(root);
				break;
			case 3:
				printf("inorder\n");
				inorder(root);
				break;
			case 4:
				printf("postorder\n");
				postorder(root);
				break;
			case 5:
				printf("balance factor");
				getbalancefactor(root);
				break;
			case 6:
				printf("heigt of tree\n");
				getheight(root);
				break;
			
			case 7:
				printf("enter the value to delete\n");
				scanf("%d",&value);
				delte(root,value);
				break;
			case 8:
				exit(0);
				break;
			default:
				printf("mismatch\n");
				break;
		}
	}
return 0;
}
