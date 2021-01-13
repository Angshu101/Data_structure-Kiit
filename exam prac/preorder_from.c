//preorder from post order and inorder
// C++ program to print Postorder traversal from given 
// Inorder and Preorder traversals. 
#include<stdio.h> 
#include<stdlib.h>
// int u=50;
int stack[50];
top=-1;
void push(int n)
{
    if(top==n){
        printf("Stack is full");
        return;
    }
    top++;
    stack[top]=n;
}
int pop(){
    int a;
     a=top--;
}

int postIndex = 0; 

// A utility function to search data in in[] 
int search(int in[], int data,int n) 
{ 
	int i = 0; 
	for (i = 0; i < n; i++) 
		if (in[i] == data) 
			return i; 
	return i; 
} 

// Fills preorder traversal of tree with given 
// inorder and postorder traversals in a stack 
void fillPre(int in[], int post[], int inStrt, 
			int inEnd, int stack[],int n) 
{ 
	if (inStrt > inEnd) 
		return; 

	// Find index of next item in postorder traversal in 
	// inorder. 
	int val = post[postIndex]; 
	int inIndex = search(in, val, n); 
	postIndex--; 

	// traverse right tree 
	fillPre(in, post, inIndex + 1, inEnd, stack, n); 

	// traverse left tree 
	fillPre(in, post, inStrt, inIndex - 1, stack, n); 

	push(val); 
} 

// This function basically initializes postIndex 
// as last element index, then fills stack with 
// reverse preorder traversal using printPre 
void printPreMain(int in[], int post[],int n) 
{    int v;
	int len = n; 
	postIndex = len - 1;  
	fillPre(in, post, 0, len - 1, stack, n); 
    int temp=top;
	while (temp > 0) 
	{ 
		printf("%d ",stack[top]); 
		v= pop(); 
        if(v==-1){
            printf("---------The end  ------\n");
            return ;
        }

	} 
} 

// Driver code 
int main() 
{ 
	int in[] = { 4, 10, 12, 15, 18, 22, 24, 25, 
				31, 35, 44, 50, 66, 70, 90 }; 
	int post[] = { 4, 12, 10, 18, 24, 22, 15, 31, 
				44, 35, 66, 90, 70, 50, 25 }; 
	int n=sizeof(in)/sizeof(int); 
	printPreMain(in, post,n); 
} 

// This code is contributed by Arnab Kundu 
