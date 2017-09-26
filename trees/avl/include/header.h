#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define HEIGHT 1
/*structure to store data ,left and right nodes of a tree*/
struct node
{
	int data;
	struct node *left;
	struct node *right;
	int height;
}*root;
/*structure to get node */
struct node *getnode(int data)
{
	struct node *temp=(struct node*) malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	temp->height=HEIGHT;
};
int max(int a,int b);
int getheight(struct node *root);
struct node *left_rotate(struct node *root);
struct node *right_rotate(struct node *root);
int getbalancefactor(struct node *root);
struct node *insert(struct node *root,int data);
struct node *minval(struct node *root);
struct node *delte(struct node *root,int data);
struct node *preorder(struct node *root);
struct node *inorder(struct node *root);
struct node *postorder(struct node *root);

