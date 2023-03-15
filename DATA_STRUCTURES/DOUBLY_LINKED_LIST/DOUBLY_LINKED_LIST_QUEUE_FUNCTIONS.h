#include<stdio.h>
#include<stdlib.h>
static int size = 0;

struct queue {
	struct queue *prev;
	int data;
	struct queue *next;
};
struct queue *head = NULL, *tail = NULL;

void enQueue(int value){
	struct queue *temp;
	temp = (struct queue *)malloc(sizeof(struct queue));
	temp->data = value;
	temp->next = NULL;
	if(head == NULL){
		temp->prev = NULL;
		head = tail = temp;
		size++;
	}
	else{
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
		size++;
	}
}

int deQueue(){
	int value;
	if(head == NULL){
		printf("\nQueue is Already Empty.\n");
		return -1;
	}
	else if(head->next == NULL){
		value = head->data;
		head = NULL;
		free(head);
		size--;
		return value;
	}
	else{
		value = head->data;
		head = head->next;
		head->prev = NULL;
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
		struct queue *temp;
		temp = tail;
		return temp->data;
	}
}

int search(int data){
	int count = 1;
	if(head == NULL)
		return -1;
	else{
		struct queue *temp;
		temp = head;
		while(temp != NULL){
			if(temp->data == data)
				return count;
			count++;
			temp = temp->next;
		}	
	free(temp);
	}
	return -1;
}

void sort(){
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

int contains(int data){
	if(head == NULL)
		return -1;
	else{
		struct queue *temp;
		temp = head;
		while(temp != NULL){
			if(temp->data == data)
				return 1;
			temp = temp->next;
		}
		free(temp);
	}
	return 0;
}

int isEmpty(){
	return head == NULL;
}
void display(){
	if(head == NULL)
		printf("\nQueue is Already Empty.\n");
	else{
		struct queue *temp;
		temp = head;
		while(temp != NULL){
			printf("%d ", temp->data);
			temp = temp->next;
		}
	}
}