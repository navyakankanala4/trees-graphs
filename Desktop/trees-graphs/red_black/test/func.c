#include "header.h"
/*function to insert*/
void insert(int data)
{
	struct node *ptr,*temp,*par;
	par=sentinel;
	ptr=root;
/*if root is not as sentinel,i.e,already few elements are present*/
	while(ptr!=sentinel)
	{
		par=ptr;
		if(data<ptr->data)
		ptr=ptr->lchild;
		else 
		ptr=ptr->rchild;
	}
/*if it is the only element*/
	temp=(struct node*) malloc(sizeof(struct node));
/*insert the element into tree and mark it's colour as red as it is the only node and leftchild and rightchild are null*/
	temp->data=data;
	temp->lchild=sentinel;
	temp->rchild=sentinel;
	temp->color=red;
	temp->parent=par;
	if(par==sentinel)
/*this is the only node so mark it as root*/
	root=temp;
	else if(temp->data<par->data)
	par->lchild=temp;
	else 
	par->rchild=temp;
	insert_balance(temp);
}

/*function for balance  factor */
void insert_balance(struct node *z)
{
	struct node *uncle,*par,*grandparent;
	/*if parent is of red colour*/
	while(z->parent->color==red)
	{
		/*storing the parent information*/
		par=z->parent;
		/*granparent info*/
		grandparent=par->parent;
		if(par=grandparent->lchild)
		{
			uncle=grandparent->rchild;
			/*recolor parent ,grandparent and uncle and point z to grandparent*/
			if(uncle ->color==red)  
			{
				par->color=black;
				uncle->color=black;
				grandparent->color=red;
				z=grandparent;
			}
			else
			{
				/*case 2 i.e,triangle case so left rotate parent*/
				if(z=par->rchild) 
				{
					left_rotate(par);
					z=par;
					par=z->parent;
				}
				/*case 3  i.e,line case so rotate grandparent and recolor*/
				par->color=black;
				grandparent->color=red;
				right_rotate(grandparent);
			}
}
		else
		{
			/*if parent is the right child of grandparent*/
			if(par==grandparent->rchild) 
			{
				/*uncle is the left child of grandparent*/
				uncle=grandparent->lchild; 
				/*if uncle is red  recolor parent uncle and grandparent and point z to grandparent*/
				if(uncle->color==red) 
				{
					par->color==black;
					uncle->color=black;
					grandparent->color=black;
					z=grandparent;
				}
				else
				{
					/*case 2 triangle case so rotate right parent*/
					if(z=par->lchild) 
					{
						right_rotate(par);
						z=par;
						par=z->parent;
					}
					/*case 3 line case so rotate grand parent and recolor ,rotation shold be away from z*/
					par->color=black;
					grandparent->color=red;
					left_rotate(grandparent);
				}
		}
	}
}
root->color=black;
}


/*function for left rotate*/
void left_rotate(struct node *pptr)
{
	struct node *temp;
	temp=pptr->rchild;/*temp is pointing to the right child of pptr*/
	pptr->rchild=temp->lchild;/*right child is pointing to the left child of temp pointer*/	
	if(temp->lchild!=sentinel)/*if it is not null*/
	temp->lchild->parent==pptr;/*setting parent pointer back in other direction*/
	temp->parent=pptr->parent;/*temp parent pointing to pptr parent*/
	if(pptr->parent !=NULL) /*if no parent node is present then make temp as root*/
	root=temp;
	else if (pptr=pptr->parent->lchild)
	pptr->parent->lchild=temp;
	else 
	pptr->parent->rchild=temp;/*temp is pointing to the right child of the pptr*/
	temp->lchild=pptr; /*temps left child is pointing to node*/
	pptr->parent=temp;/*pptr parent is pointing to temp*/
}
/*function for right rotate*/
void right_rotate(struct node *pptr)
{
	struct node *temp;
	temp=pptr->lchild;/*temp is pointing to the right child of pptr*/
	pptr->lchild=temp->rchild;/*right child is pointing to the left child of temp pointer*/
	if(temp->rchild!=NULL)/*if it is not null*/
	temp->rchild->parent==pptr;/*setting parent pointer back in other direction*/
	temp->parent=pptr->parent;/*temp parent pointing to pptr parent*/
	if(pptr->parent !=NULL) /*if no parent node is present then make temp as root*/
	root=temp;
	else if (pptr=pptr->parent->rchild)
	pptr->parent->rchild=temp;
	else 
	pptr->parent->lchild=temp;/*temp is pointing to the right child of the pptr*/ 
	temp->rchild=pptr; /*temps left child is pointing to node*/
	pptr->parent=temp;/*pptr parent is pointing to temp*/
}
/*function for display*/
void display(struct node *ptr,int level)
{
	int i;
	if(ptr!=NULL)
	{
		display(ptr->rchild,level+1);
		printf("\n");
		for(i=0;i<level;i++)
		printf(" ");
		printf("%d",ptr->data);
		if(ptr->color=red)
		printf("R");
		else
		printf("B");
		display(ptr->lchild,level+1);
	}
}
