#include<stdio.h>
#include<stdlib.h>
static int size = 0;

struct stack {
	struct stack *prev;
	int data;
	struct stack *next;
};
 struct stack *head = NULL, *tail = NULL;

void push(int value){
	struct stack *temp;
	temp = (struct stack *)malloc(sizeof(struct stack));
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

int pop(){
	int value;
	if(head == NULL){
		printf("\nStack is Already Empty.\n");
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
		struct stack *temp, *ptr;
		temp = head;
		ptr = NULL;
		while(temp->next != NULL){
			ptr = temp;
			temp = temp->next;
		}
		value = temp->data;
		ptr->next = NULL;
		tail = ptr;
		free(temp);
		size--;
		return value;
	}
}

int peek(){
	if(head == NULL){
		printf("\nStack is Empty.\n");
		return -1;
	}
	else{
		struct stack *temp;
		temp = tail;
		return temp->data;
	}
}

int search(int data){
	int count = 1;
	if(head == NULL)
		return -1;
	else{
		struct stack *temp;
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

int contains(int data){
	if(head == NULL)
		return -1;
	else{
		struct stack *temp;
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
		printf("\nStack is Already Empty.\n");
	else{
		struct stack *temp;
		temp = head;
		while(temp != NULL){
			printf("%d ", temp->data);
			temp = temp->next;
		}
	}
}