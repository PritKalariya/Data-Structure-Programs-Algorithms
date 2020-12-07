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
	int ch;
	
	while(1) {
		printf("\nMenu\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Exit\n");
		
		printf("Enter your choice: ");
		scanf("%d", &ch);
		
		switch(ch) {
			case 1: insert();
					break;
					
			case 2: del();
					break;
					
			case 3: exit(0);
			
			default: printf("\nINVALID INPUT!!\n");
		}	
	}
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
	
	printf("\nData entered successfully.\n");
}

void del() {
	struct node *cur; // target/current node
	struct node *p; // parent
	int ele;
	
	printf("Enter the element you want to delete: ");
	scanf("%d", &ele);
	
	if(root == NULL) {
		printf("\nTree is empty!!\n");
		return;
	}
	
	// parent node is the one to which the child is attached to
	// current is the child node (to be deleted)
	// travelling till the parent and child node
	while(ele) {
		p = cur;
		
		if(ele < cur->data) {
			cur = cur->left;
		}
		else {
			cur = cur->right;
		}
	}
	
	// Case1: Having no child
	if(cur->left == NULL && cur->right == NULL) {
		p->left = NULL;
		printf("\n%d deleted successfully.\n", cur->data);
		free(cur);
	}
}