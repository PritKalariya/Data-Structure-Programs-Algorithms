// Stack operations using STATIC memory loocation

#include<stdio.h>
#include<stdlib.h>

#define CAPACITY 5 // Decalring a pre-processor macro varaiable

int stack[CAPACITY]; // A noamal variable cannot be passed, hence we created a macro variable
int top = -1; // Variable pointing to the indexes of the stack

void main() {
	
	int ch, ele;
	
	while(1) {
		printf("\n Menu \n");
		printf("1. Insert (push)\n");
		printf("2. Remove (pop)\n");
		printf("3. Peek (Display the last element)\n");
		printf("4. Display (Traverse)\n");
		printf("5. Exit\n");
	
		printf("Enter your choice: ");
		scanf("%d", &ch);
		
		switch(ch) {
			case 1: printf("Enter the element: ");
					scanf("%d", &ele);
					insert(ele);
					break;
					
			case 2: del();
					break;
					
			case 3: ele = peek();
					printf("\n%d is the last entered value.\n", ele);
					break;
					
			case 4: traverse();
					break;
					
			case 5: exit(0);
			
			default: printf("\nInvalid input!\n");
		}
	}
}

// 1. Adding new value
void insert(int ele) {
	if(isFull()) {
		printf("\nSTACK OVERFLOW!!\n");
	}
	else {
		top++;
		stack[top] = ele;
		printf("\n%d is inserted in the stack.\n", ele);
	}
}

int isFull() {
	if(top == CAPACITY-1) {
		return 1; // True
	}
	else {
		return 0; // False
	}
}

// 2. Deleting the last entered value
void del() {
	if(isEmpty()) {
		printf("\nSTACK IS EMPTY!!\n");
	}
	else {
		printf("%d removed.", stack[top]);
		return stack[top--];	
	}
}

int isEmpty() {
	if(top == -1) {
		return 1; // True
	}
	else {
		return 0; // False
	}
}

// 3. Displaying the last entered value
int peek() {
	if(isEmpty()) {
		printf("\nSTACK IS EMPTY!!\n");
	}
	else {
		return stack[top];
	}
}

// 4. Display the whole stack
void traverse() {
	int i;
	
	if(isEmpty()) {
		printf("\nSTACK IS EMPTY!!\n");
	}
	else {
		printf("The stack : ");
		for(i = 0; i<=top; i++) {
			printf("%d\t\n", stack[i]);
		}
	}
}










