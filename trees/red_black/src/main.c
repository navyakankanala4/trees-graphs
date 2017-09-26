#include "header.h"
struct node *root;
struct node *sentinel;
int main()
{
	int data,ch;
	/*sentinel is the parent of root node*/
	sentinel=(struct node *) malloc(sizeof(struct node));
	sentinel->data=-1;
	sentinel->color=black;
	root=sentinel;
	while(1)
	{
		printf("1.insert\n");
		printf("2.display\n");
		printf("3.exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the element to insert\n");
				scanf("%d",&data);
				insert(data);
				break;
			case 2:
				printf("display the elements present in rb_tree\n");
				display(root,0);
				break;
			case 3:
				exit(0);
				break;
			default:
				printf("mismatch\n");
				break;
		}
	}
	return 0;
}

