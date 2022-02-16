/*
*Binary search Tree operations 
*Date: 16-feb-2022
*Farhan Ashraf
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

void printPostorder(struct node* node)
{
	if (node == NULL)
		return;

	printPostorder(node->left);

	printPostorder(node->right);

	printf("%d\n", node->data);
}

void printInorder(struct node* node)
{
	if (node == NULL)
		return;

	printInorder(node->left);

	printf("%d\n", node->data);

	printInorder(node->right);
}

void printPreorder(struct node* node)
{
	if (node == NULL)
		return;

	printf("%d\n", node->data);

	printPreorder(node->left);

	printPreorder(node->right);
}

int main()
{
    int k=5,o;
	int a[k];
	for(int i=0;i<k;i++)
	{
		scanf("%d",&a[i]);
	}

	struct node* root = newNode(a[0]);
	root->left = newNode(a[1]);
	root->right = newNode(a[2]);
	root->left->left = newNode(a[3]);
	root->left->right = newNode(a[4]);

	printf("Preorder traversal of binary tree is \n");
	printPreorder(root);

	printf("Inorder traversal of binary tree is \n");
	printInorder(root);

	printf("Postorder traversal of binary tree is \n");
	printPostorder(root);

	return 0;
}