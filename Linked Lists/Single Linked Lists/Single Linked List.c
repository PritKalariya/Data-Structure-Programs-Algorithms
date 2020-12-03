// Single linked list operations

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* link;
};

// root variable has the base address of the list. 
struct node* root = NULL;

// Prototypes
void append(void);
void add_at_begin(void);
void add_at_after(void);
int len(void);
void display(void);
void del(void);

void main() {
	
	int ch, length;
	
	while(1) {
		printf("\nMenu\n");
		printf("1. Append\n");
		printf("2. Add at begin\n");
		printf("3. Add at after\n");
		printf("4. Length\n");
		printf("5. Display\n");
		printf("6. Delete a node\n");
		printf("7. Reverse\n");
		printf("8. Exit\n");
		
		printf("Enter your choice: ");
		scanf("%d", &ch);
		
		switch(ch) {
			case 1: append();
					break;
					
			case 2: add_at_begin();
					break;
					
			case 3: add_at_after();
					break;
					
			case 4: length = len();
					printf("\nThe length of the list is %d\n", length);
					break;
					
			case 5: display();
					break;
					
			case 6: del();
					break;
				
			case 7: reverse();
					break;
					
			case 8: exit(1);
			
			default: printf("\nINVALID INPUT!!\n");
		}
	}
}

// 1. Append a new node
void append() {
	struct node *temp;
	
	temp = (struct node*)malloc(sizeof(struct node));
	
	printf("Enter node data: ");
	scanf("%d", &temp->data);
	temp->link = NULL;
	
	if(root == NULL) {
		root = temp;
	}
	else {
		struct node* p;
		
		p = root;
		
		while(p->link != NULL) {
			p = p->link;
		}
		
		p->link = temp;
	}
	
	printf("\nData entered successfully.\n");
}

// 2. Add at Begin
void add_at_begin() {
	struct node *temp;
	
	temp = (struct node*)malloc(sizeof(struct node));
	
	printf("Enter node data: ");
	scanf("%d", &temp->data);
	temp->link = NULL;
	
	if(root == NULL) {
		root = temp;
	}
	else {
		temp->link = root;
		root = temp;
	}

	printf("\nNode added successfully.\n");
}

// 3. Add at after
void add_at_after() {
	struct node *temp;
	int loc;
	
	printf("Enter new node location: ");
	scanf("%d", &loc);
	
	if(loc > len()) {
		printf("\nINVALID LOCATION\n");
	}
	else {
		struct node *p;
		int i = 1;
		
		p = root;
		
		while(i < loc) {
			p = p->link;
			i++;
		}
		
		temp = (struct node*)malloc(sizeof(struct node));
		
		printf("Enter node data: ");
		scanf("%d", &temp->data);
		temp->link = NULL;
		
		// Insertion
		temp->link = p->link;
		p->link = temp;
		
		printf("\nData Entered successfully.\n");
	}
}

// 4. Length
int len() {
	int count = 0;
	struct node* temp;
	temp = root;
	
	while(temp != NULL) {
		count++;
		temp = temp->link;
	}
	
	return count;
}

// 5. Display
void display() {
	struct node* temp;
	temp = root;
	
	if(temp == NULL) {
		printf("\nLIST IS EMPTY!!\n");
	}
	else {
		printf("\n");
		while(temp != NULL) {
			printf("%d\t", temp->data);
			temp = temp->link;
		}
		printf("\n");
	}
}

// 6. delete
void del() {
	struct node* temp;
	int loc;
	
	printf("Enter the node location you want to delete: ");
	scanf("%d", &loc);
	
	if(loc > len()) {
		printf("\nINVALID LOCATION!!\n");
	}
	else if(loc == 1) {
	
		temp = root;
		root = temp->link;
		temp->link = NULL;
		
		free(temp);

		printf("\nFirst node deleted successfully.\n");
	}
	else if(loc == len()) {
		struct node *p, *q;
		int i = 1, j = 1;
		
		p = q = root;
		
		while(i < loc) {
			p = p->link;
			i++;
		}
		
		while(j < loc - 1) {
			q = q->link;
			j++;
		}
		
		q->link = NULL;
		
		free(p);
		
		printf("\nLast node deleted successfully.\n");
	}
	else {
		struct node* p;
		struct node* q;
		int i = 1;
		
		p = root;
		
		while(i < loc) {
			p = p->link;
			i++;
		}
		
		q = p->link;
		q->link = p->link;
		p->link = NULL;
		free(q);

		printf("\nNode deleted successfully.\n");
	}
}

// 7. Reverse
void reverse() {
	struct node *p, *q;
	int i, j, k, temp, length;
	
	length = len();
	
	i = 0;
	j = length - 1;
	p = q = root;
	
	while(i < j) {
		k = 0;
		
		// pointing the *q to the last node
		while(k < j) {
			q = q->link;
			k++;
		}
		
		// Shifting the elements
		temp = p->data;
		p->data = q->data;
		q->data = temp;
		
		i++;
		q--;
		p = p->link; // Shifting the pointer to the right
		q = root; // reassigning to root to make it point to 2nd last node using while(k<j)
	}
	
	printf("\nNode successfully reversed.\n");
}