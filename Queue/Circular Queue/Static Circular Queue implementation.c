// static circular queue operations

#include<stdio.h>
# define CAPACITY 5

int cq[CAPACITY];
int front = -1;
int rear = -1;

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
					
			case 4: exit(1);
			
			default: printf("\nInvalid Input!!\n");
		}
	}
}

void insert() {
	int ele;
	
	printf("Enter the element you want to insert: ");
	scanf("%d", &ele);
	
	if((front == rear + 1) || (CAPACITY == rear + 1)) {
		printf("\nThe queue is full!!\n");
	}
	else if(front == -1 && rear == -1) {
		front = 0;
		rear = 0;
		cq[rear] = ele;
		printf("\n%d successfully inserted.\n", ele);
	}
	else if(rear == CAPACITY + 1) {
		rear = 0;
		cq[rear] = ele;
		printf("\n%d successfully inserted.\n", ele);
	}
	else {
		rear++;
		cq[rear] = ele;
		printf("\n%d successfully inserted.\n", ele);
	}
}

void del() {
	if(front == -1 && rear == -1) {
		printf("\nThe queue is empty!!\n");
	}
	else if(front == rear) {
		printf("\n%d deleted.\n", cq[front]);
		front = -1;
		rear = -1;
	}
	else if(front == CAPACITY + 1) {
		printf("\n%d deleted.\n", cq[front]);
		front = 0;
	}
	else {
		printf("\n%d deleted.\n", cq[front]);
		front++;
	}
}

void display() {
	int i, j;
	
	if(front == -1 && rear == -1) {
		printf("\nThe queue is empty!!\n");
	}
	else if(front < rear) {
		printf("\n");
		for(i=front; i<=rear; i++) {
			printf("%d\t", cq[i]);
		}
		printf("\n");
	}
	else {
		printf("\n");
		for(i=front; i<CAPACITY; i++) {
			printf("%d\t", cq[i]);
		}
		
		for(j=0; j<rear; j++) {
			printf("%d\t", cq[j]);
		}
		printf("\n");
	}
}
