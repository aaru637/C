#include<stdio.h>
#include<stdlib.h>
static int size = 0;

struct stack{
	int data;
	struct stack *next;
};
struct stack *head = NULL;

void push(int value){
	struct stack *temp, *ptr;
	temp = (struct stack *)malloc(sizeof(struct stack));
	temp->data = value;
	if(head == NULL){
		temp->next = NULL;
		head = temp;
		size++;
	}
	else{
		ptr = head;
		while(ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = temp;
		temp->next = NULL;
		size++;
	}
}

int pop(){
	int value;
	if(head == NULL){
		printf("\nStack is Empty.\n");
		return -1;
	}
	else if(size == 1){
		value = head->data;
		head = head->next;
		size--;
		return value;
	}
	else{
		int data;
		struct stack *temp, *prev;
		temp = head;
		prev = NULL;
		while(temp->next != NULL){
			prev = temp;
			temp = temp->next;
			data = temp->data;
		}
		prev->next = NULL;
		size--;
		free(temp);
		return data;
	}
}

int peek(){
	if(head == NULL){
		printf("\nStack is Empty.\n");
		return -1;
	}
	else{
		int value;
		struct stack *temp;
		temp = head;
		while(temp != NULL){
			value = temp->data;
			temp = temp->next;
		}
		return value;
	}
}

int contains(int value){
	if(head == NULL){
		printf("\nStack is Empty.\n");
		return -1;
	}
	else{
		struct stack *temp;
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
		struct stack *temp;
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
		struct stack *ptr1, *ptr2;
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
		printf("\nStack is Empty.\n");
	else{
		struct stack *temp;
		temp = head;
		while(temp != NULL){
			printf("%d ", temp->data);
			temp = temp->next;
		}
	}
}