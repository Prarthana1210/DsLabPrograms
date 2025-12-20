/* WAP to simulate the working of a queue of integers
using an array. Provide the following operations: Insert,
Delete, Display
The program should print appropriate */

#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;
void insert() {
    int item;
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert.\n");
    } else {
        if (front == -1)
            front = 0;
        printf("Enter element to insert: ");
        scanf("%d", &item);
        rear++;
        queue[rear] = item;
        printf("Element %d inserted successfully.\n", item);
    }
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Cannot delete.\n");
    } else {
        printf("Deleted element: %d\n", queue[front]);
        front++;
    }
}
void display() {
    int i;
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice = 1;

    while (choice != 4) {
        printf("\nQueue Operations \n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            insert();
        }
        else if (choice == 2) {
            delete();
        }
        else if (choice == 3) {
            display();
        }
        else if (choice == 4) {
            printf("Exiting program.\n");
        }
        else {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
