#include <stdio.h>

void enqueue(int);
void dequeue();
void display();

int items[], front = -1, rear = -1;

void enqueue(int value) {
    if (front == -1)
      front = 0;
    rear++;
    items[rear] = value;
    printf("\nInserted -> %d\n", value);
  }



void dequeue() {
  if (front == -1)
    printf("\nQueue  is Empty!!");
  else {
    printf("\nDeleted : %d", items[front]);
    front++;
    if (front > rear)
      front = rear = -1;
  }
}

void display() {
  if (rear == -1)
    printf("\nQueue  is Empty!!!");
  else {
    int i;
    printf("\nQueue  elements are:\n");
    for (i = front; i <= rear; i++)
      printf("%d  ", items[i]);
  }
  printf("\n");
}

