/*WAP to Implement Singly Linked List with following
operations
a) Createalinkedlist.
b) Insertion of a node at first position, at any position and
at end of list.Display the contents of the linked list.
WAP to Implement Singly Linked List with following
operations
a) Create a linked list.
b) Deletion of first element, specified element and last
element in the list.
c) Display the contents of the linked list*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
int info;
struct node* next;
};
struct node* start=NULL;
//create a node
struct node* createNode(int data){
struct node*p=(struct node*)malloc(sizeof(struct node));
p->info=data;
p->next=NULL;
return p;
}
//create a AtFirst place
void createList(int data)
{
    struct node* p=createNode(data);
    if(start==NULL){
        start=p;
        return;
    }
    else{
        struct node* temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=p;
    }
}
//insert at first
void insertAtFirst(int data)
{
    struct node* p=createNode(data);
    p->next=start;
    start=p;
}
void insertAtEnd(int data)
{
    createList(data);
}
void insertAtPos(int data,int pos)
{
    struct node* p=createNode(data);
    if(pos==1){
        insertAtFirst(data);
        return;
    }
    struct node* temp=start;
    for(int i=1;i<pos-1 && temp!=NULL;i++)
        temp=temp->next;
    if(temp==NULL){
        printf("INVALID POSITION\n");
        return;
    }
    else
    {
        p->next=temp->next;
        temp->next=p;
    }
}
//delete first node
void deleteFirst()
{
    if(start==NULL){
        printf("Invalid position\n");
        return;
    }
    struct node* temp=start;
    start=temp->next;
    free(temp);
}
//delete end node
void deleteLast()
{
    if(start==NULL)
    {
        printf("list is empty\n");
        return;
    }
    if(start->next=NULL)
    {
        free(start);
        start=NULL;
        return;
    }
    struct node* temp=start;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next->next);
    temp->next=NULL;
}
void deleteAtPos(int pos)
{
    if(start==NULL){
        printf("empty list\n");
        return;
    }
    else if(pos=1){
            deleteFirst();
    }
    else{
        struct node* temp=start;
        for(int i=1;i<=pos-1&&temp!=NULL;i++){
            temp=temp->next;
        }
        if(temp==NULL || temp->next==NULL){
            printf("position not found\n");
            return;
        }
        struct node* follow=temp->next;
        temp->next=follow->next;
        free(follow);
    }
}
void display(){
    if(start==NULL){
            printf("list is empty\n");
    }
    struct node* temp=start;
    while(temp!=NULL)
    {
        printf("%d\n",temp->info);
        temp=temp->next;
    }
    printf("\n");
    }
int main()
{
    createList(20);
    createList(30);
    createList(80);
    display();
    insertAtFirst(67);
    display();
    insertAtEnd(90);
    display();
    insertAtPos(78,6);
    display();
    insertAtPos(77,8);
    display();
    deleteFirst();
    display();
    deleteLast();
    display();
    deleteAtPos(5);
    display();
    deleteAtPos(9);
    return 0;
}













