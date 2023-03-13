#include<stdio.h>
#include<stdlib.h>

static int size = 0;

struct queue{
	int data;
	struct queue *next;
};
struct queue *head = NULL, *tail = NULL;
void enQueue(int value){
	struct queue *temp, *ptr;
	temp = (struct queue *)malloc(sizeof(struct queue));
	temp->data = value;
	if(head == NULL){
		temp->next = NULL;
		head = temp;
		size++;
	}
	else{
		temp->next = NULL;
		tail->next = temp;
		size++;
	}
	tail = temp;
}

int deQueue(){
	if(head == NULL){
		printf("\nQueue is Empty.\n");
		return -1;
	}
	else{
		int value = head->data;
		head = head->next;
		size--;
		return value;
	}
}

int peek(){
	if(head == NULL){
		printf("\nQueue is Empty.\n");
		return -1;
	}
	else{
		return tail->data;
	}
}

int contains(int value){
	if(head == NULL){
		printf("\nQueue is Empty.\n");
		return -1;
	}
	else{
		struct queue *temp ;
		temp = head;
		while(temp != NULL){
			if(temp->data == value)
				return 1;
			temp = temp->next;
		}
		return 0;
	}
}

int isEmpty(){
	return size == 0;
}

int search(int value){
	if(head == NULL){
		printf("\nStack is Empty.\n");
		return -1;
	}
	else{
		struct queue *temp;
		int count = 1;
		temp = head;
		while(temp != NULL){
			if(temp->data == value)
				return count;
			temp = temp->next;
			count++;
		}
		return -1;
	}
}

void sort(){
	if(head == NULL){
		printf("\nStack is Empty.\n");
	}
	else{
		struct queue *ptr1, *ptr2;
		int temp;
		ptr1 = head;
		while(ptr1 != NULL){
			ptr2 = ptr1->next;
			while(ptr2 != NULL){
				if(ptr1->data > ptr2->data){
					temp = ptr1->data;
					ptr1->data = ptr2->data;
					ptr2->data = temp;
				}
				ptr2 = ptr2->next;
			}
			ptr1 = ptr1->next;
		}
	}
}

void display(){
	if(head == NULL)
		printf("\nQueue is Empty.\n");
	else{
		struct queue *temp ;
		temp = head;
		while(temp != NULL){
			printf("%d ", temp->data);
			temp = temp->next;
		}
	}
}