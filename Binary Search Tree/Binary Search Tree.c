// Binary Search Tree

#include<stdio.h>
#include<stdlib.h>

struct node {
	struct node *left;
	int data;
	struct node *right;
};

struct node *root = NULL;

void main() {
	insert();
}

void insert() {
	struct node *t; // temp
	struct node *p; // parent
	
	t = (struct node*)malloc(sizeof(struct node));
	
	printf("Enter node data: ");
	scanf("%d", &t->data);
	t->left = t->right = NULL;
	
	p = root;
	
	if(root == NULL) {
		root = t;
	}
	else {
		struct node *cur; // current node
		
		cur = root;
		
		while(cur) {
			p = cur;
			
			if(t->data > cur->data) {
				cur = cur->right;
			}
			else {
				cur = cur->left;
			}
		}
		
		if(t->data > p->data) {
			p->right = t;
		}
		else {
			p->left = t;
		}
	}
}
