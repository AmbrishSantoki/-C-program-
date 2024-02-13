#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int data[MAX_SIZE];
bool filled[MAX_SIZE];
int front = -1;
int rear = -1;

// Function to check if the queue is empty
bool isEmpty() {
    return (front == -1 && rear == -1);
}

// Function to check if the queue is full
bool isFull() {
    return (rear == MAX_SIZE - 1);
}

// Function to add an element to the queue
void enqueue(int element) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    // Find the first available position
    int position = 0;
    while (filled[position]) {
        position++;
    }

    // Add the element to the first available position
    data[position] = element;
    filled[position] = true;

    // Update front and rear if the queue was empty
    if (isEmpty()) {
        front = position;
        rear = position;
    }
}

// Function to remove an element from the queue by index
void removeByIndex(int index) {
    if (isEmpty()) {
        printf("Queue is empty. Cannot remove.\n");
        return;
    }

    if (index < 0 || index > MAX_SIZE - 1) {
        printf("Invalid index. Cannot remove.\n");
        return;
    }

    // Mark the position as empty
    filled[index] = false;

    // If the removed element is at the front, update the front
    if (index == front) {
        while (front < MAX_SIZE && !filled[front]) {
            front++;
        }
    }

    // If the removed element is at the rear, update the rear
    if (index == rear) {
        while (rear >= 0 && !filled[rear]) {
            rear--;
        }
    }
}

// Function to find and remove an element from the queue
void removeElement(int element) {
    if (isEmpty()) {
        printf("Queue is empty. Cannot remove.\n");
        return;
    }

    // Find the element in the queue and remove it
    for (int i = 0; i < MAX_SIZE; i++) {
        if (filled[i] && data[i] == element) {
            removeByIndex(i);
            printf("Element %d removed from the queue.\n", element);
            return;
        }
    }

    // If the element is not found
    printf("Element %d not found in the queue.\n", element);
}

// Function to print the queue data
void printQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (filled[i]) {
            printf("%d ", data[i]);
        }
    }
    printf("\n");
}

int main() {
	int n=0,element=0,turn=1;
	printf("Enter number element in queue\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&element);
		enqueue(element);
	}
    printQueue();

    while(turn!=0){
        printf("If you insert element then put 1\nIf you remove element then put 2 else \nPut 0\n");
        scanf("%d",&turn);
        if(turn==1){
            scanf("%d",&element);
		    enqueue(element);
        }
        else if(turn ==2){
            scanf("%d",&element);
            removeByIndex(element);
        }
        printQueue();
        
    }
    return 0;
}

