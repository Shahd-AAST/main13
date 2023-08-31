#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
  struct Node {
  int data;
  Node *next;
  };

  Node *head = NULL;

  Node *makeNode(int x) {
  Node *p = (Node *)malloc(sizeof(Node));
  p->data = x;
  p->next = NULL;
  return p;
}

  void insertFront(int x) {

  Node *p = makeNode(x);

  if (head != NULL) {
    p->next = head;
    head =p;
    }

    head = p;
    }


  void insertEnd(int x) {

  Node *p = makeNode(x);

  if (head == NULL) {
    head = p;
    return;
    }

  Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
    }

  temp->next = p;
  }


 void insertPosition(int x, int position) {
  if (position <= 0) {
    printf("you are out of linked list\n");
    return;
  }

  Node *p = makeNode(x);

  if (position == 1) {
    p->next = head;
    head = p;
    return;
  }

  Node *temp = head;
  int count = 1;

  while (temp != NULL && count < position - 1) {
    temp = temp->next;
    count++;
  }

  if (temp == NULL) {
    printf(" you are out of linked list\n");
    return;
  }

  p->next = temp->next;
  temp->next = p;
 }

  void display() {
  if (head == NULL) {
    printf("List is empty\n");
    return;
    }
   Node *temp = head;
   while (temp != NULL) {
     printf("%d => ", temp->data);
     temp = temp->next;
     }
     printf("\n");
     }

int main(){
insertFront(3);
insertFront(2);
insertFront(1);
insertEnd(4);
insertEnd(5);
insertPosition(20,4);
display();

    return 0;
}
