// Implementation of Stack using Single Linked List

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *link;
};

struct node *top = NULL;

void main() {
	int ch;
	
	while(1) {
		printf("\nMENU\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		
		printf("Enter your choice: ");
		scanf("%d", &ch);
		
		switch(ch) {
			case 1: insert();
					break;
					
			case 2: del();
					break;
					
			case 3: display();
					break;
					
			case 4: exit(0);
			
			default: printf("\nWrong input!\n");
		}
	}
}

void insert() {
	struct node *temp;
	
	temp = (struct node*)malloc(sizeof(struct node));
	
	printf("Enter node data: ");
	scanf("%d", &temp->data);
	
	temp->link = top;
	top = temp;
	
	printf("\nNode inserted successfully.\n");
}

void del() {
	struct node *temp;
	
	if(top == NULL) {
		printf("\nSTACK IS EMPTY!!\n");
	}
	else {
		temp = top;
		
		printf("\n%d node deleted.\n", temp->data);
		
		top = top->link;
		temp->link = NULL;
		
		free(temp);
	}
}

void display() {
	struct node *temp;
	
	if(top == NULL) {
		printf("\nSTACK IS EMPTY!!\n");
	}
	else {
		temp = top;
		
		while(temp != NULL) {
			printf("\n%d\n", temp->data);
			temp = temp->link;
		}
	}
}
