#include<stdio.h>
#include<stdlib.h>
/*the node is of structure type that stores color left right and parent details*/
struct node
{
	enum {black, red} color;
	int data;
	struct node *lchild;
	struct node *rchild;
	struct node *parent;
};
/*function definitions to insert ,balance ,rotate and display*/
void insert(int data);
void insert_balance(struct node *z);
void left_rotate(struct node *z);
void right_rotate(struct node *z);
void display(struct node *z,int level);
struct node *root;
/*sentinel is used to represent parent of the root*/
struct node *sentinel;
