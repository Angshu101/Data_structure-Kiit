#include <stdio.h>
#include <stdlib.h>

// Data Structure to store a linked list node
struct Node
{
	int data;
	struct Node* next;
};

// Helper function to print given linked list
void printList(struct Node* head)
{
	struct Node* ptr = head;
	while (ptr)
	{
		printf("%d -> ", ptr->data);
		ptr = ptr->next;
	}

	printf("NULL\n");
}

// Helper function to insert new Node in the beginning of the linked list
void push(struct Node** head, int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = *head;

	*head = newNode;
}

// Iterative function to reverse first k nodes of linked list
struct Node* reverseK(struct Node** current, int k)
{
	struct Node* prev = NULL;
	int count = 0;

	// Iterate through the list and move/insert each node to the
	// front of the result list (like a push of the node)
	while (*current && count++ < k)
	{
		// tricky: note the next node
		struct Node* next = (*current)->next;

		// move the current node onto the result
		(*current)->next = prev;

		// update previous pointer to current node
		prev = *current;

		// move to next node in the list
		*current = next;
	}

	// return last processed node
	return prev;
}

// Function to reverse every group of k nodes in given linked list
struct Node *reverseInGroups(struct Node *head, int k)
{
	// base case
	if (head == NULL)
		return NULL;

	// start with current node
	struct Node* current = head;

	// reverse next k nodes
	struct Node* prev = reverseK(&current, k);

	// recur for remaining nodes
	head->next = reverseInGroups(current, k);

	// important - return previous (to link every group of k nodes)
	return prev;
}

// main method
int main(void)
{
	// input keys
	int keys[10],num ;
	//int n = sizeof(keys)/sizeof(keys[0]);

	struct Node *head = NULL;
    printf("Enter 10 elements");

	for (int i = 0; i < 10; i++){
        scanf("%d",&keys[i]);
		push(&head, keys[i]);
        
    }
    printf("THE ELEMENTS ARE");
    printList(head);
    printf("The value of groups you wANT to divide:-");
    scanf("%d",&num);
	head = reverseInGroups(head, num);
    printf("The resultant is :- \n");
	printList(head);

	return 0;
}