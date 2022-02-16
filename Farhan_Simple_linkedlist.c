/*
*Simple linkedlist
*Date 16-feb-2022
*Farhan Ashraf
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
   int data;
   struct node *next;
};

void linklisttraverse(struct node* ptr)
{
struct node *temp;
temp=ptr;

while(temp!=0)
{
printf(" Element: %d\n",temp->data);
temp=temp->next;
}

}

struct node * insertAtFirst(struct node *head,int data)
{

struct node * ptr=(struct A*)malloc (sizeof(struct A));
ptr->next=head;
ptr->data=data;return ptr;

}



struct node * insertIndex(struct A *head,int data,int index)
{
struct node * ptr=(struct node*)malloc (sizeof(struct node));
 struct node *p=head;
int i=0;
while(i!=index-1)
{

   p=p->next;
     i++;
}
ptr->data=data;
ptr->next=p->next;
p->next=ptr;
}

struct node * insertEnd(struct node *head,int data)
{
struct node * ptr=(struct node*)malloc (sizeof(struct node));
 ptr->data=data;
struct node * p=head;

while(p->next!=0)
{

   p=p->next;
   
}
p->next=ptr;
ptr->next= 0;
return head;

}


struct  node* deleteFirst( struct node * head)
{
struct node * ptr=head;
head=head->next;
free (ptr);
return head;
}

struct  node* deleteAtIndex( struct node * head,int index)
{
struct node *p=head;
struct node *q=head->next;
for(int i=0;i<index-1;i++)
{
p=p->next;
q=q->next;
}
p->next=q->next;
free(q);
return head;
}


struct  node* deletelast( struct node * head)
{
struct node *p=head;
struct node *q=head->next;
while(q->next!=0)
{
p=p->next;
q=q->next;
}
p->next=0;
free(q);
return head;
}

void main()
{
struct node *head,*second,*third,*forth;

head =(struct node *)malloc(sizeof(struct node));
second =(struct node *)malloc(sizeof(struct node));
third =(struct node *)malloc(sizeof(struct node));
forth =(struct node *)malloc(sizeof(struct node));

head-> info=23;
head-> link=second;


second-> info=26;
second-> link=third;


third-> info=29;
third-> link=forth;

forth-> info=30;
forth-> link=0;

printf("Linklist before insertion & deletion\n ");
linklisttraverse(head);

int l,z,q;
printf("Enter any no:\n1.for Insert No in Starting\n2.for Insert No in between\n3.for Insert No in Last\n");
scanf("%d",&l);

switch(l)
{
case 1:
{
printf("\nEnter a no you want to Insert\n");
scanf("%d",&z);
  head=insertAtFirst(head,z);
break;
}
case 2:
{
printf("\nEnter a no you want to Insert & index\n");
scanf("%d%d",&z,&q);
head =insertIndex(head,z,q);
break;
}
case 3:
{
printf("\nEnter a no you want to Insert\n");
scanf("%d",&z);
head=insertEnd(head,z);
break;
}

case 4:
{
printf("\ndeleting first element of the linked list\n");
head = deleteFirst(head);
break;
}
case 5:
{
printf("\nEnter a index no for deleting the linked list\n");
scanf("%d",&z);
head = deleteAtIndex(head, z);
break;
}
case 6:
{
printf("\nEnter a index no for deleting the linked list\n");
scanf("%d",&z);
head = deleteAtLast(head);
break;
}
}
printf("Linklist after insertion & deleting\n ");
linklisttraverse(head);

}
