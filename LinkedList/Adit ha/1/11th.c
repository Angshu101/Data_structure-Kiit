#include <stdio.h>
#include <stdlib.h>

// Data Structure to store a linked list node
struct Node
{
	int data;
	struct Node *next;
};

// Helper function to insert new node in the beginning of the linked list
void push(struct Node** headRef, int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->data = data;
	newNode->next = *headRef;
	*headRef = newNode;
}

// Helper function to print the linked list
void printList(char *msg, struct Node *node)
{
	printf("%s: ", msg);
	while (node) {
		printf("%d -> ", node->data);
		node = node->next;
	}
	printf("NULL\n");
}

// Function to swap k'th node from the beginning with the
// k'th node from the end in a linked list
void swapNodes(struct Node **headRef, int k)
{
	struct Node *x, *y, *prev_x = NULL, *prev_y = *headRef;

	// find k'th node from the beginning and store it in x
	// also calculate previous node of x and store it in prev_x
	struct Node *curr = *headRef;
	for (int i = 1; i < k && curr; i++) {
		prev_x = curr;
		curr = curr->next;
	}
	x = curr;

	// k is more than number of nodes, X and Y don’t exist
	if (curr == NULL)
		return;

	// find k'th node from the end and store it in y
	// also calculate previous node of y and store it in prev_y
	struct Node *ptr = *headRef;
	while (curr->next) {
		prev_y = ptr;
		ptr = ptr->next;
		curr = curr->next;
	}
	y = ptr;

	// Y is next to X (X -> Y)
	if (x->next == y)
	{
		x->next = y->next;
		y->next = x;
		prev_x->next = y;
	}

	// X is next to Y (Y -> X)
	else if (y->next == x)
	{
		y->next = x->next;
		x->next = y;
		prev_y->next = x;
	}

	// X is head node
	else if (x == *headRef)
	{
		*headRef = y;
		y->next = x->next;
		prev_y->next = x;
		x->next = NULL;
	}

	// Y is head node
	else if (y == *headRef)
	{
		*headRef = x;
		x->next = y->next;
		prev_x->next = y;
		y->next = NULL;
	}

	// otherwise
	else {
		ptr = y->next;
		y->next = x->next;
		x->next = ptr;

		prev_x->next = y;
		prev_y->next = x;
	}
}

int main(void)
{
	int arr[10] ;
	//unsigned n = sizeof(arr)/sizeof(arr[0]);

	struct Node *head = NULL;
    printf("Enter 10 eleemts :- \n");
	for (int i = 0; i <10; i++){
       scanf("%d",&arr[i]);
		push(&head, arr[i]);
    }

	printList("Before", head);

	int k;
    printf("Enter the value of k:- ");
    scanf("%d",&k);
    printf("\n");
	swapNodes(&head, k);

	printList("After ", head);

	return 0;
}