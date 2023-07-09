// Addition of Two Polynomials.

#include<stdio.h>
#include<stdlib.h>

struct node {
	int exponent;
	int coefficient;
	struct node *next;
};

struct node *addBeg(struct node *head, int exponent, int coefficient){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->exponent = exponent;
	temp->coefficient = coefficient;
	temp->next = NULL;
	if(head == NULL)
		head = temp;
	else{
		temp->next = head;
		head = temp;
	}
	return head;
}

struct node *addPos(struct node *head, int pos, int exponent, int coefficient){
	if(pos == 1){
		head = addBeg(head, exponent, coefficient);
		return head;
	}
	else{
		struct node *temp, *temp1;
		temp = (struct node *)malloc(sizeof(struct node));
		temp->exponent = exponent;
		temp->coefficient = coefficient;
		temp->next = NULL;
		temp1 = head;
		for(int i = 1 ; i < pos - 1 ; i++)
			temp1 = temp1->next;
		if(temp1->next == NULL){
			temp1->next = temp;
		}
		else{
			temp->next = temp1->next;
			temp1->next = temp;
		}
		return head;
	}
}

struct node *addSort(struct node *head, int exponent, int coefficient){
	int count = 2;
	struct node *temp = head;
	if(head == NULL || exponent > head->exponent)
		head = addBeg(head, exponent, coefficient);
	else{
		while(temp->next != NULL && temp->next->exponent > exponent){
			temp = temp->next;
			count++;
		}
		head = addPos(head, count, exponent, coefficient);
	}
	return head;
}

struct node *addPoly(struct node *first, struct node *second, struct node *result){
	struct node *firsttemp, *secondtemp;
	int coef, expo;
	int count = 1;
	firsttemp = first, secondtemp = second;
	while(firsttemp != NULL || secondtemp != NULL){
		if(firsttemp->exponent == secondtemp->exponent){
			coef = firsttemp->coefficient + secondtemp->coefficient;
			expo = firsttemp->exponent;
			result = addPos(result, count, expo, coef);
			firsttemp = firsttemp->next;
			secondtemp = secondtemp->next;
		}
		else if(firsttemp->exponent > secondtemp->exponent){
			result = addPos(result, count, firsttemp->exponent, firsttemp->coefficient);
			firsttemp = firsttemp->next;
		}
		else{
			result = addPos(result, count, secondtemp->exponent, secondtemp->coefficient);
			secondtemp = secondtemp->next;
		}
		count++;
	}
	while(firsttemp != NULL){
		result = addPos(result, count, firsttemp->exponent, firsttemp->coefficient);
		firsttemp = firsttemp->next;
		count++;
	}
	while(secondtemp != NULL){
		result = addPos(result, count, secondtemp->exponent, secondtemp->coefficient);
		secondtemp = secondtemp->next;
		count++;
	}
	return result;
}


void display(struct node *head){
	struct node *temp = head;
	while(temp != NULL){
		printf("%dx^%d ", temp->coefficient, temp->exponent);
		temp = temp->next;
		if(temp != NULL)
			printf("+ ");
	}
	printf("\n\n");
}


int main(){
	struct node *first , *second, *result;
	first = second = result = NULL;
	first = addSort(first, 2, 5);
	first = addSort(first, 3, 5);
	first = addSort(first, 10, 2);
	first = addSort(first, 1, 5);
	printf("First Polynomial : ");
	display(first);
	second = addSort(second, 2, 5);
	second = addSort(second, 3, 5);
	second = addSort(second, 4, 6);
	second = addSort(second, 10, 2);
	second = addSort(second, 1, 5);
	printf("Second Polynomial : ");
	display(second);
	result = addPoly(first, second, result);
	printf("Result Polynomial : ");
	display(result);
}