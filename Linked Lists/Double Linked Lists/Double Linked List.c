// Double Linked List
#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *left;
	int data;
	struct node *right;
};

struct node *root = NULL;

void main() {
	int ch, len;
	
	while(1) {
		printf("\nMENU\n");
		printf("1. Append.\n");
		printf("2. Add at the begin.\n");
		printf("3. Add at after.\n");
		printf("4. Length.\n");
		printf("5. Display.\n");
		printf("6. Delete.\n");
		printf("7. Exit.\n");
		
		printf("\nEnter you choice: ");
		scanf("%d", &ch);
		
		switch(ch) {
			case 1: append();
					break;
					
			case 2: add_at_begin();
					break;
					
			case 3: add_at_after();
					break;
					
			case 4: len = length();
					printf("The length of the list is %d.", len);
					break;
					
			case 5: display();
					break;
				
			case 6: del();
					break;
					
			case 7: exit(0);
			
			default: printf("\nINVALID INPUT!!\n");
		}
	}
}

// Case 1
void append() {
	struct node *temp;
	
	temp = (struct node *)malloc(sizeof(struct node));
	
	printf("\nEnter node data: ");
	scanf("%d", &temp->data);
	
	temp->left = NULL;
	temp->right = NULL;
	
	if(root == NULL) {
		root = temp;
	}
	else {
		struct node *p;
		
		p = root;
		
		while(p->right != NULL) {
			p = p->right;
		}
		
		p->right = temp;
		temp->left = p;
	}
	
	printf("\nData entered successfully.\n");
}

// Case 2
void add_at_begin() {
	struct node *temp;
	
	temp = (struct node *)malloc(sizeof(struct node));
	
	printf("\nEnter node data to add at begin: ");
	scanf("%d", &temp->data);
	
	temp->left = NULL;
	temp->right = NULL;
	
	if(root == NULL) {
		root = temp;
	}
	else {
		temp->right = root;
		root->left = temp;
		root = temp;
	}
	
	printf("\nData entered successfully.\n");
}

// Case 3
void add_at_after() {
	struct node *temp, *p;
	int loc, len, i = 1;
	
	printf("\nEnter the location you want to enter the node: ");
	scanf("%d", &loc);
	
	len = length();
	
	if(loc > len) {
		printf("\nINVALID LOCATION!!\n");
		printf("\nThe list has only %d nodes.", len);
	}
	else {
		temp = (struct node*)malloc(sizeof(struct node));
		
		printf("\nEnter node data: ");
		scanf("%d", &temp->data);
		
		temp->left = NULL;
		temp->right = NULL;
		
		p = root;
		
		while(i < loc) {
			p = p->right;
			i++;
		}
		
		//Right side connections
		temp->right = p->right;
		p->right->left = temp;
		
		//Left side connections
		temp->left = p;
		p->right = temp;
	}
	
	printf("\nData entered successfully.\n");
}

// Case 4
int length() {
	struct node *temp = root;
	int count = 0;
	
	if(temp == NULL) {
		printf("\nTHE LIST IS EMPTY!!\n");
	}
	else {
		while(temp != NULL) {
			count++;
			temp = temp->right;
		}
	}
	
	return count;
}

// Case 5
void display() {
	struct node *temp = root;
	
	if(temp == NULL) {
		printf("\nTHE LIST IS EMPTY!!\n");
	}
	else {
		while(temp != NULL) {
			printf("%d\t", temp->data);
			temp = temp->right;
		}
		printf("\n");
	}
}

// Case 6 
void del() {
	struct node *temp;
	int loc, len;
	
	printf("Enter the location of the node you want to delete: ");
	scanf("%d", &loc);
	
	len = length();
	
	if(loc > len) {
		printf("\nINVALID LOCATION!!\n");
		printf("\nThe list has only %d nodes.\n", len);
	}
	else if(loc == 1) {
		temp = root;
		
		root = root->right;
		root->left = NULL;
		
		free(temp);
		
		printf("\nFirst node deleted successfully.\n");
	}
	else if(loc == len) {
		struct node *p;
		struct node *q;
		int i = 1;
		
		p = root;
		
		while(i < loc) {
			p = p->right;
			i++;
		}
		
		q = p->left;
		
		q->right = NULL;
		
		free(p);
		
		printf("\nLast node delted successfully.\n");
	}
	else {
		struct node *p;
		struct node *q;
		int i = 1;
		
		p = root;
		
		while(i < loc) {
			p = p->right;
			i++;
		}
		
		q = p->left;
		
		p->right->left = q;
		q->right = p->right;
		
		free(p);
		
		printf("\nNode deleted successfully.\n");
	}
}