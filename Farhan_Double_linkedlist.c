/*
*Doublelinkedlist
*Date: 16-feb-2022
*Farhan Ashraf
*/
#include <stdio.h>
#include <stdlib.h>


struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};


void insertFront(struct Node** head, int data) {
 
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

 
  newNode->data = data;

 
  newNode->next = (*head);


  newNode->prev = NULL;

 
  if ((*head) != NULL)
    (*head)->prev = newNode;

  (*head) = newNode;
}


void insertAfter(struct Node* prev_node, int data) {

  if (prev_node == NULL) {
    printf("previous node cannot be null");
    return;
  }


  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  newNode->data = data;

  newNode->next = prev_node->next;

 
  prev_node->next = newNode;

 
  newNode->prev = prev_node;

 
  if (newNode->next != NULL)
    newNode->next->prev = newNode;
}


void insertEnd(struct Node** head, int data) {
 
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

 
  newNode->data = data;

 
  newNode->next = NULL;

 
  struct Node* temp = *head;

 
  if (*head == NULL) {
    newNode->prev = NULL;
    *head = newNode;
    return;
  }

 
  while (temp->next != NULL)
    temp = temp->next;

 
  temp->next = newNode;

 
  newNode->prev = temp;
}


void deleteNode(struct Node** head, struct Node* del_node) {
 
  if (*head == NULL || del_node == NULL)
    return;

 
  if (*head == del_node)
    *head = del_node->next;

   
  if (del_node->next != NULL)
    del_node->next->prev = del_node->prev;

 
  if (del_node->prev != NULL)
    del_node->prev->next = del_node->next;

 
  free(del_node);
}

void displayList(struct Node* node) {
  struct Node* last;

  while (node != NULL) {
    printf("%d->", node->data);
    last = node;
    node = node->next;
  }
  if (node == NULL)
    printf("NULL\n");
}

int main() {
 
  struct Node* head = NULL;
int i;

 
 
int op;
while (op!=4)
{
printf("Enter any no:\n1.for Insert No in Starting\n2.traverse of lists\n3. is delete for node\n4 is exit\n ");
scanf("%d",&i);

switch(i)
{
case 1:
{
int f,l;
printf("\nEnter a no you want to Insert front first\n");
scanf("%d",&f);
insertFront(&head, f);
for(i=0;i<4;i++)
{
printf("\nEnter a no you want to Insert next\n");
scanf("%d",&i);
insertAfter(head,i);

break;
}
}

case 2:
{


  displayList(head);
break;
}


case 3:
{

 
  deleteNode(&head, head->next);
break;

  //displayList(head);
}

case 4:
{
op=4;
}
}

}
}