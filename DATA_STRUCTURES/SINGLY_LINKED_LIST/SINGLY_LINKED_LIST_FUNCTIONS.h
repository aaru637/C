#include<stdio.h>
#include<stdlib.h>
static int size = 0;
struct node {
	int data;
	struct node *next;
} ;
struct node *head = NULL;

void addBeg(int data){
	struct node *temp, *ptr;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	if(head == NULL){
		temp->next = NULL;
		head = temp;
		size++;
	}
	else{
		temp->next = head;
		head = temp;
		size++;
	}
}

void addPos(int data, int pos){
	struct node *temp , *ptr;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	if(pos == 0)
		addBeg(data);
	else if(pos > size || pos < 0)
		printf("Invalid Position.");
	else{
		ptr = head;
		for(int i = 1 ; i < pos ; i++)
			ptr = ptr->next;
		temp->next = ptr->next;
		ptr->next = temp;
		size++;
	}
}

void addEnd(int data){
	struct node *temp, *ptr;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	if(head == NULL)
		addBeg(data);
	else{
		ptr = head;
		while(ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = temp;
		temp->next = NULL;
		size++;
	}
}

void delBeg(){
	if(head == NULL)
		printf("List is Already Empty.");
	else{
		head = head->next;
		size--;
	}
}

void delPos(int pos){
	struct node *temp, *prev;
	if(head == NULL)
		printf("List is Already Empty.");
	else if(pos == 0)
		delBeg();
	else if(pos >= size || pos < 0)
		printf("Invalid Position.");
	else{
		temp = head;
		prev = NULL;
		for(int i = 1 ; i <= pos ; i++){
			prev = temp;
			temp = temp->next;
		}
		prev->next = temp->next;
		free(temp);
		size--;
	}
}


void delEnd(){
	struct node *temp, *prev;
	if(head == NULL)
		printf("List is Already Empty.");
	else if(size == 1)
		delBeg();
	else{
		temp = head;
		prev = NULL;
		while(temp->next != NULL){
			prev = temp;
			temp = temp->next;
		}
		prev->next = NULL;
		free(temp);
		size--;
	}
}

int search(int data){
	int count = 1;
	if(head == NULL)
		return -1;
	else{
		struct node *temp;
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
	struct node *ptr1, *ptr2;
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
		struct node *temp;
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
		printf("List is Empty.");
	else{
		struct node *temp = head;
		while(temp != NULL){
			printf("%d ", temp->data);
			temp = temp->next;
		}
	}
}