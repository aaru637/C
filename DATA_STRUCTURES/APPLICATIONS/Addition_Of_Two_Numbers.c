#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *getData(int data){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

struct node *push(struct node *head, int data){
	struct node *temp = getData(data);
	if(head == NULL){
		temp->next = NULL;
		head = temp;
	}
	else{
		temp->next = head;
		head = temp;
	}
	return head;
}

struct node *enqueue(struct node *head, int data){
	struct node *temp = getData(data);
	struct node *traversal = head;
	if(head == NULL){
		head = push(head, data);
		return head;
	}
	else{
		while(traversal->next)
			traversal = traversal->next;
		traversal->next = temp;
	}
	return head;
}

struct node *addTwoNum(struct node *first, struct node *second, struct node *result){
	struct node *firsttemp = first, *secondtemp = second;
	int sum = 0, carry = 0;
	while(firsttemp || secondtemp){
		sum = 0;
		if(firsttemp)
			sum += firsttemp->data;
		if(secondtemp)
			sum += secondtemp->data;
		carry = sum / 10;
		sum %= 10;
		result = push(result, sum);
		if(firsttemp)
			firsttemp = firsttemp->next;
		if(secondtemp)
			secondtemp = secondtemp->next;
	}
	if(carry)
		result = push(result, carry);
	return result;
}

void display(struct node *head){
	struct node *temp = head;
	while(temp->next){
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("%d\n", temp->data);
	printf("\n");
}

int main(){
	struct node *first = NULL, *second = NULL, *result = NULL, *firsttemp = NULL, *secondtemp = NULL;
	int value1 = 543, value2 = 543;
	int copy1 = value1, copy2 = value2;
	while(copy1 != 0){
		firsttemp = push(firsttemp, copy1 % 10);
		copy1 /= 10;
	}
	while(copy2 != 0){
		secondtemp = push(secondtemp, copy2 % 10);
		copy2 /= 10;
	}
	display(firsttemp);
	display(secondtemp);
	while(value1 != 0){
		first = enqueue(first, value1 % 10);
		value1 /= 10;
	}
	while(value2 != 0){
		second = enqueue(second, value2 % 10);
		value2 /= 10;
	}
	result = addTwoNum(first, second, result);
	display(result);
}