// Binary Search Tree

#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *left;
	int data;
	struct node *right;
};

struct node *root = NULL;

// function declarations were missing in original code
// added function declarations
void insert();
void delete (int data);
struct node *deleteNode(int data, struct node *node);
struct node *getPredecessor(struct node *node);
void traverse();
void traverseInorder(struct node *node);

void main()
{
	insert(); //50
	insert(); //30
	insert(); //20
	insert(); //40
	insert(); //70
	insert(); //60
	insert(); //80
	traverse();
	delete (20);
	traverse();
	delete (30);
	traverse();
	delete (50);
	traverse();
}

void insert()
{
	struct node *t; // temp
	struct node *p; // parent

	t = (struct node *)malloc(sizeof(struct node));

	printf("Enter node data: ");
	scanf("%d", &t->data);
	t->left = t->right = NULL;

	if (root == NULL)
	{
		root = t;
	}
	else
	{
		struct node *cur; // current node

		cur = root;

		while (cur)
		{
			p = cur;

			if (t->data > cur->data)
			{
				cur = cur->right;
			}
			else
			{
				cur = cur->left;
			}
		}

		if (t->data > p->data)
		{
			p->right = t;
		}
		else
		{
			p->left = t;
		}
	}
}

void delete (int data)
{
	if (root != NULL) // checking if tree is not empty
	{
		root = deleteNode(data, root);
	}
}
struct node *deleteNode(int data, struct node *node)
{
	if (node == NULL) //base case for recursion
	{
		return node;
	}
	if (data < node->data) //go to left subtree
	{
		node->left = deleteNode(data, node->left);
	}
	else if (data > node->data) //go to right subtree
	{
		node->right = deleteNode(data, node->right);
	}
	else //we reached at the node to be deleted
	{
		if (node->left == NULL && node->right == NULL)
		{
			// node to be deleted is leaf node
			printf("Removing leaf node...\n");
			free(node);
			return NULL;
		}
		if (node->left == NULL)
		{
			// node to be deleted has single right child
			struct node *tempNode;
			printf("Removing a node with single right child...\n");
			tempNode = node->right;
			free(node);
			return tempNode;
		}
		else if (node->right == NULL)
		{
			// node to be deleted has single left child
			struct node *tempNode;
			printf("Removing a node with single left child...\n");
			tempNode = node->left;
			free(node);
			return tempNode;
		}

		// node to be deleted has 2 children
		struct node *tempNode;
		printf("Removing a node with two children...\n");
		tempNode = getPredecessor(node->left);				 //getting pointer to node's inorder predecessor from left subtree
		node->data = tempNode->data;						 //putting predecessor's data to node
		node->left = deleteNode(tempNode->data, node->left); //recursively deleting predecessor node which is easy to remove as it will always be a leaf node
	}
	return node;
}

// helper function to get predecessor of node
struct node *getPredecessor(struct node *node)
{
	if (node->right)
	{
		return getPredecessor(node->right);
	}
	return node;
}

// Added functions to perform inorder traversal and to test the code
// function to traverse tree(inorder)
void traverse()
{
	if (root != NULL)
	{
		printf("Inorder traversal : ");
		traverseInorder(root);
	}
	printf("\n");
}

// helper function for traverse function
void traverseInorder(struct node *node)
{
	if (node->left != NULL)
	{
		traverseInorder(node->left);
	}
	printf("%d  ", node->data);
	if (node->right)
	{
		traverseInorder(node->right);
	}
}
