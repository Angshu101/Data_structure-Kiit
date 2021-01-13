#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    struct node *left,*right;
    int data ;
}bst ;
bst *newNode(int d){
    bst *temp=(struct node*)malloc(sizeof(bst));
    temp->right=NULL;
    temp->left=NULL;
    temp->data=d;

    return(temp);
}
void printinorder(bst *node){
    if (node==NULL)
    return;
    printinorder(node->left);
    printf(" %d,",node->data);
    printinorder(node->right);

}
void printpreorder(bst *node){
    if(node==NULL)
    return;
    printf(" %d,",node->data);
    printpreorder(node->left);
    printpreorder(node->right);
}
void printpostorder(bst *node)
{
    if(node==NULL)
    return;
    printpostorder(node->left);
    printpostorder(node->right);
    printf(" %d,",node->data);
}
struct node* insert(bst *node,int key)
{
    if(node==NULL)
    {
       return newNode(key);
    }
    else if(key<node->data)
    {
        node->left=insert(node->left,key);
      }
    else if(key>node->data){
        node->right=insert(node->right,key);
    }
    else{
    node->data=key;
    }
    return node;
}
unsigned int countleafnode(bst *node)
{
    if(node==NULL)
    return 0;
    if(node->left==NULL && node->right==NULL)
    return 1;
    else 
    return(countleafnode(node->left)+countleafnode(node->right));
}
int countNonleaf(bst* node) 
{ 
    // Base cases. 
    if (node == NULL || (node->left == NULL &&  
                         node->right == NULL)) 
        return 0; 
  
    // If root is Not NULL and its one of its 
    // child is also not NULL 
    return 1 + countNonleaf(node->left) +  
               countNonleaf(node->right); 
} 
int addBT(bst* node) 
{ 
    if (node == NULL) 
        return 0; 
    return (node->data+ addBT(node->left) + addBT(node->right)); 
} 
int maxDepth(struct node* node)  
{ 
   if (node==NULL)  
       return 0; 
   else 
   { 
       /* compute the depth of each subtree */
       int lDepth = maxDepth(node->left); 
       int rDepth = maxDepth(node->right); 
  
       /* use the larger one */
       if (lDepth > rDepth)  
           return(lDepth+1); 
       else return(rDepth+1); 
   } 
}  
int main(){
    int ch,n,ele;
    printf("Ener the value of the root ");
    scanf("%d",&n);
    struct node *root = NULL;
    root = insert(root,n );
    while(1)
    {
        printf("---------MENU------------\n");
        printf("1.  Insert node  \n");
        printf("2.  print inorder  \n");
        printf("3.  print preorder  \n");
         printf("4.  print postorder  \n");
         printf("5. Count nunber of leaf nodes  \n");
         printf("6.  Count the number of non leaf nodes  \n");
         printf("7. Sum of all nodes \n");
         printf("8.  Maximum depth \n");
         printf("------Enter your choice---   :- ");
         scanf("%d",&ch);
         switch(ch)
         {                                                             

                  case 1:  printf("Enter element :-");
                            scanf("%d",&ele);
                            insert(root,ele);
                             break;
                  case 2:printpreorder(root);
                          break;
                  case 3: printinorder(root);
                          break;
                  case 4: printpostorder(root);
                          break;
                  case 5: printf("The number of leaf nodes in the tree is :- %d ",countleafnode(root));
                          break;
                  case 6: printf("The number of non leaf nodes are :- %d",countNonleaf(root));
                          break;
                  case 7 :  printf(" The sum of all nodes :- %d",addBT(root));
                           break;
                  case 8:   printf("The maximum height is %d",maxDepth(root));
                            break;
                  case 9:  
                        exit(0);
                        break;
                  default:
                  printf("WRONG CHOICE");
             
         }

    }
     return 0; 

}