
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(){
        data=0;
        next=NULL;
    }
};
Node*head=NULL;
void push(int val){
    Node *new_node=new Node();
    new_node->data=val;
    new_node->next=head;
    head=new_node;

}
void delete_node(int key){
    cout<< " hi";
  Node *temp=head;
  Node *prev=NULL;
  //deleting the head
  if(temp!=NULL && temp->data==key ){
      head=temp->next;
      return;
  }
  if(temp==NULL){
      cout <<"The List is Empty";
      return;
  }
 while(temp!=NULL && temp->data!=key){
     prev=temp;
    temp=temp->next;
     
 }
 prev->next=temp->next;
}
void printlist()
{
    Node *temp;
    temp=head;
    while(temp!=NULL){
        cout <<temp->data<<"-->";
        temp=temp->next;
    }
}
int main(){
    for(int i=0;i<20;i++){
        push(i);
    }
    cout <<"The Linked list is ";
    
    //delete_node(10);
    printlist();
    return 0;
}