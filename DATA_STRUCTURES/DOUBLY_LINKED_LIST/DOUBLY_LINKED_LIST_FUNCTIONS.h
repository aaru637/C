#include<stdio.h>
#include<stdlib.h>

static int size = 0;

struct list {
	struct list *prev;
	int data;
	struct list *next;
};
struct list *head = NULL, *tail = NULL;

void addBeg(int value){
	struct list *temp;
	temp = (struct list *)malloc(sizeof(struct list));
	temp->data = value;
	temp->next = head;
	if(head == NULL){
		tail = temp;
		size++;
	}
	else{
		temp->next = head;
		size++; 
	}
	head = temp;
}

void addPos(int value, int pos){
	if(pos == 0)
		addBeg(value);
	else if(pos < 0 || pos > size)
		printf("\nInvalid Position.\n");
	else{
		struct list *temp, *ptr;
		temp = (struct list *)malloc(sizeof(struct list));
		temp->data = value;
		ptr = head;
		for(int i = 1 ; i < pos ; i++)
			ptr = ptr->next;
		temp->next = ptr->next;
		temp->prev = ptr;
		if(ptr == tail)
			tail = temp;
		else
			ptr->next->prev = temp;
		ptr->next = temp;
		size++;
	}
}

void addEnd(int value){
	struct list *temp, *ptr;
	temp = (struct list *)malloc(sizeof(struct list));
	temp->data = value;
	temp->next = NULL;
	if(head == NULL){
		tail = temp;
		head = temp;
		size++;
	}
	else{
		ptr = tail;
		ptr->next = temp;
		temp->prev = ptr;
		tail = temp;
		size++;
	}
}

void delBeg(){
	if(head == NULL)
		printf("\nList is Already Empty.\n");
	else if(head->next == NULL){
		head = NULL;
		free(head);
		size--;
	}
	else{
		head = head->next;
		head->prev = NULL;
		size--;
	}
}

void delPos(int pos){
	if(head == NULL)
		printf("\nList is Already Empty.\n");
	else{
		if (pos == 0)
			delBeg();
		else if(pos < 0 || pos >= size)
			printf("\nInvalid Position.\n");
		else{
			struct list *ptr, *temp;
			temp = head, ptr = NULL;
			for(int i = 1 ; i <= pos ; i++){
				ptr = temp;
				temp = temp->next;
			}
			ptr->next = temp->next;
			if(ptr == tail)
				ptr->next = NULL;
			else
				temp->prev = ptr;
			size--;
		}
	}
}

void delEnd(){
	if(head == NULL){
		printf("\nList is Already Empty.\n");
		return;
	}
	else if(head->next == NULL){
		head = NULL;
		free(head);
		size--;
	}
	else{
		struct list *temp, *ptr;
		temp = head;
		ptr = NULL;
		while(temp->next != NULL){
			ptr = temp;
			temp = temp->next;
		}
		ptr->next = NULL;
		tail = ptr;
		free(temp);
		size--;
	}
}

int search(int data){
	int count = 1;
	if(head == NULL)
		return -1;
	else{
		struct list *temp;
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
	struct list *ptr1, *ptr2;
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
		struct list *temp;
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
		printf("\nList is Already Empty.\n");
	else{
		struct list *temp;
		temp = head;
		while(temp != NULL){
			printf("%d ", temp->data);
			temp = temp->next;
		}
	}
}