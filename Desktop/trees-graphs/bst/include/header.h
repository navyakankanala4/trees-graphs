#include<stdlib.h>
#include<stdio.h>
/*structure named node to store the data of node and left and right nodes of a tree*/
struct node
{
	int data;
	struct node *left;
	struct node *right;
}node,*root,*temp;
struct node* findmin(struct node *root);
struct node* findmax(struct node *root);
struct node *insert(struct node *root,int data);
struct node *search(struct node *root,int data);
struct node *delete(struct node *root,int data);
struct node *preorder(struct node *root);
struct node *inorder(struct node *root);
struct node *postorder(struct node *root);
struct node *display();

