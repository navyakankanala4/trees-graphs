#include "header.h"
/*main function*/			
int main()
{
	int sw,value;

	while(1)
	{
		printf("Enter your choice.\n1.Insert element\n2.search element \n3.Display element \n4.delete element\n5.preorder\n6.inorder\n7.postorder\n8.maximum\n9.minimum\n10.Exit\n");
		scanf("%d",&sw);
		switch(sw)
		{
			case 1:
				printf("enter the data to inseert the data into a binary tree\n");	
				scanf("%d",&value);
				insert(root,value);
				break;
			case 2:
				printf("enter the value  of the node to be serached\n");
				scanf("%d",&value);
				search(root,value);
				break;

			case 3:
				printf("display the elements present in the bst\n");
				display();
				break;
			case 4:
				printf("enter the value to delete from  bst\n");
				scanf("%d",&value);
				delete(root,value);
				break;
			case 5:
	
				preorder(root);
				printf("preorder traversal\n");
				break;
			case 6:
	
				inorder(root);
				printf("inorder traversal\n");
				break;
			case 7:
	
				postorder(root);
				printf("post order traversal\n");
				break;
			case 8:
	
				findmax(root);
				printf("maximum element present in the tree\n");
				break;
			case 9:
				printf("minimum element present in the tree\n");
				findmin(root);
				break;
			case 10:
				exit(0);
				break;
			default:
				printf("match not found\n");
				break;
		}
	}
}
