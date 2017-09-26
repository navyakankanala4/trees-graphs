#include "header.h"
/*function to find minimum value in tree*/
struct node* findmin(struct node *root)
{
	/*if There is no element in the tree */
        if(root==NULL)
        {
               
                return NULL;
        }
	/* Go to the left sub tree to find the min element */
        if(root->left) 
                return findmin(root->left);
        else 
                return root;
}
/*function to find the maximum value in tree*/
struct node* findmax(struct node *root)
{
	
        if(root==NULL)
        {
                
                return NULL;
        }
	/* Go to the right sub tree to find the min element */
        if(root->right) 
                findmax(root->right);
        else 
                return root;
}
/*function to insert an element into tree*/
struct node *insert(struct node *root,int data)
{
	struct node *temp;
	struct node *current;
	/*if root is empty insert there*/
	if(root==NULL)
	{
		
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=data;
		temp->left=NULL;
		temp->right=NULL;
	}
	/*store the current in root*/
	root=current;
	/*if the data in root is more than the data */
	if(data<root->data)
	{
		/*point current to left of current*/
		current=current->left;
		/*if it is null then store the element there*/
		if(current==NULL)
		{
		root->left=temp;
		}
	}
	else 
	{
		/*if the value in the root is less than data move right */
		current=current->right;
		if(current==NULL)
		{
		/*if it is null then store the element there*/
		root->right=temp;
		}
	}
}
/*function to search an element in the tree*/
struct node *search(struct node *root,int data)
{
	struct node *current=root;
	while(current->data!=data)
	{
		if(current!=NULL)
		printf("%d",current->data);
		/*data in the root is greater than data goleft else go right*/
		if(current->data>data)
		current=current->left;
		else
		current=current->right;
		if(current==NULL)
		printf("element not found\n");
		return current;
	}
}
/*function to delete*/
struct node *delete(struct node *root,int data)
{
	if(root==NULL)
	{
		printf("no elements presentin the tree\n");
		return root;
	}
	/*if the data is less go to left subtree else right subtree*/
	else if(data<root->data)
	root->left=delete(root->left,data);
	else if(data>root->data)
	root->right=delete(root->right,data);
	else
        {  
                if(root->right && root->left)
                {
                        temp = findmin(root->right);
                        root -> data = temp->data; 
                        root -> right = delete(root->right,temp->data);
                }
                else
                {                  
                        temp = root;
                        if(root->left == NULL)
                                root = root->right;
                        else if(root->right == NULL)
                                root = root->left;
                        free(temp); 
                }
        }
        return root;
}
/*function to print the data in preorder like root->left->right*/
struct node *preorder(struct node *root)
{
	if(root==NULL)
	return 0;
	printf("data present at root:%d\n",root->data);
	preorder(root->left);
	preorder(root->right);
}
/*function to print the data in inorder left->root->right*/
struct node *inorder(struct node *root)
{
	if(root==NULL)
	return 0;
	inorder(root->left);
	printf("data present at root is  %d\n",root->data);
	inorder(root->right);
}
/*function toprint the data in postorder left->right->root*/
struct node *postorder(struct node *root)
{
	if(root==NULL)
	return 0;
	postorder(root->left);
	postorder(root->right);
	printf("data present at root is  %d\n",root->data);
}
/*function to display the data at root*/
struct node *display()
{
	printf("element at root is:%d\n",root->data);
}
