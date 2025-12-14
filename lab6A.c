/*WAP to Implement Single Link List with following
operations:
Sort the linked list, Reverse the linked list,
Concatenation of two linked lists.*/
#include<stdio.h>
#include<stdlib.h>
struct node{
int info;
struct node* next;
};
struct node* createNode(int data)
{
    struct node* p=(struct node*)malloc(sizeof(struct node));
    p->info=data;
    p->next=NULL;
    return p;
};
void insertNode(struct node** start,int data)
{
    struct node* p=createNode(data);
    if(*start==NULL)
    {
       *start=p;
       return;
    }
    struct node* temp=*start;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=p;
}
void display(struct node* start){
struct node* temp=start;
if(start==NULL){
    printf("list is empty\n");
    return;
}
while(temp!=NULL)
{
    printf("%d\n",temp->info);
    temp=temp->next;
}
printf("\n");
}
//sorting the list
void sortList(struct node* start)
{
    struct node* i;
    struct node* j;
    int temp;
    for(i=start;i!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(i->info >j->info){
            temp=i->info;
            i->info=j->info;
            j->info=temp;
            }
        }
    }
}
//reverse list
struct node* reverseList(struct node* start)
{
    struct node* prev=NULL;
    struct node* next=NULL;
    while(start!=NULL)
    {
        next=start->next;
        start->next=prev;
        prev=start;
        start=next;
    }
    return prev;
}
struct node* concatenateNode(struct node* head1,struct node* head2)
{
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    struct node* temp=head1;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head2;
    return head1;
};
int main(){
    struct node* list1=NULL;
    struct node* list2=NULL;
    int choice,value;
    while(1){
        printf("\n MENU\n");
        printf("1.insert into list1\n,2.insert into list2\n,3.display list1\n 4.display list2\n 5.sort list1\n 6.sort list2 \n 7.concatenate list2 into list 1\n 8. Exit\n");
        printf("enter choice \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("enter value: \n");
                scanf("%d",&value);
                insertNode(&list1,value);
                break;
            case 2:
                printf("enter value: \n");
                scanf("%d",&value);
                insertNode(&list2,value);
                break;
            case 3:
                printf("display all the elements of the list1\n");
                display(list1);
                break;
            case 4:
                printf("display all the elements of the list1\n");
                display(list2);
                break;
            case 5:
                sortList(list1);
                printf("sorted list1\n");
                break;
            case 6:
                sortList(list2);
                printf("sorted list2\n");
                break;
            case 7:
                list1=concatenateNode(list1,list2);
                printf("list concatenated(list2 appends to list).\n");
                break;
            case 8:
                exit(0);
            default:
                printf("invalid choice.\n");
        }
    }
    return 0;
}




