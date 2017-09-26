#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define HEIGHT 1
struct node
{
	int data;
	struct node *left;
	struct node *right;
	int height;
}*root;
struct node *getnode(int data)
{
	struct node *temp=(struct node*) malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	temp->height=HEIGHT;
}
int max(int a,int b)
{
	if(a>b)
	return a;
	else 
	return b;
}
int getheight(struct node *root)
{
	if(root==NULL)
	return 0;
	return max(getheight(root->left),getheight(root->right)+1);

}
struct node *left_rotate(struct node *root)
{
	struct node *right=root->right;
	struct node *left=right->left;
	/*update rotation*/
	right->left=root;
	root->right=left;
	/*update height*/
	root->height=max(getheight(root->left),getheight(root->right)+1);
	root->height=max(getheight(right->left),getheight(right->right)+1);
}
struct node *right_rotate(struct node *root)
{
	struct node *left=root->left;
	struct node *right=left->right;
	/*update rotation*/
	left->right=root;
	root->left=right;
	/*update height*/
	root->height=max(getheight(root->right),getheight(root->left)+1);
	root->height=max(getheight(left->right),getheight(left->left)+1);
}
int getbalancefactor(struct node *root)
{
	if(root==NULL)
	return 0;
	return (getheight(root->left)-getheight(root->right));
}

struct node *insert(struct node *root,int data)
{
	if(root==NULL)
	{
		struct node *temp=getnode(data);
		return temp;
	}
	if(root->data>data)
	root->left=insert(root->left,data);
	if(root->data<data)
	root->right=insert(root->right,data);
	/*update height*/
	root->height=max(getheight(root->left),getheight(root->right)+1);
	int balance=getbalancefactor(root);
	/*left-left*/
	if((balance>1)&&(root->left->data)>data)
	{
		root=right_rotate(root);
	}
	/*right right*/
	else if((balance<1)&&(root->right->data)<data)
	{
		root=left_rotate(root);
	}
	/*left-right*/
	else if((balance>1)&&(root->left->data)<data)
	{
		root->left=left_rotate(root->left);
		root=right_rotate(root);
	}
	/*right-left*/
	else if((balance<1)&&(root->right->data)>data)
	{
		root->right=right_rotate(root->right);
		root=left_rotate(root);
	}
	return root;
}
struct node *minval(struct node *root)
{
	struct node *current=root;
	/*find the leftmost leaf*/
	while(current->left!=NULL)
	current=current->left;
	return current;
}
struct node *delte(struct node *root,int data)
{
	if(root==NULL)
	return root;
	if(data<root->data)
	root->left=delte(root->left,data);
	else if(data>root->data)
	root->right=delte(root->right,data);
	else
	{
		/*if the node has no child or one child*/
		if(root->left==NULL||root->right==NULL)
		{
			struct node *temp=root->left?root->left:root->right;
			/*no child case*/
			if(temp==NULL)
			{
				temp=root;
				root=NULL;
			}
			else
			{
				*root=*temp;
				free(temp);
			}
		}
		else
		{
			struct node *temp=minval(root->right);
			root->data=temp->data;
			root->right=delte(root->right,temp->data);
		}
	}
	if(root==NULL)
	return root;
	/*update height*/
	root->height=max(getheight(root->left),getheight(root->right)+1);
	int balance=getbalancefactor(root);
	/*left-left*/
	if((balance>1)&&(root->left->data)>data)
	{
		root=right_rotate(root);
	}
	/*right right*/
	else if((balance<1)&&(root->right->data)<data)
	{
		root=left_rotate(root);
	}
	/*left-right*/
	else if((balance>1)&&(root->left->data)<data)
	{
		root->left=left_rotate(root->left);
		root=right_rotate(root);
	}
	/*right-left*/
	else if((balance<1)&&(root->right->data)>data)
	{
		root->right=right_rotate(root->right);
		root=left_rotate(root);
	}
	return root;
}

struct node *preorder(struct node *root)
{
	if(root==NULL)
	return 0;
	printf("value of the root node %d->",root->data);
	preorder(root->left);
	preorder(root->right);
}
struct node *inorder(struct node *root)
{
	if(root==NULL)
	return 0;
	inorder(root->left);
	printf("value of the root node is:%d->",root->data);
	inorder(root->right);
}
struct node *postorder(struct node *root)
{
	if(root==NULL)
	return 0;
	postorder(root->left);
	postorder(root->right);
	printf("value at the root node:%d->",root->data);
}

