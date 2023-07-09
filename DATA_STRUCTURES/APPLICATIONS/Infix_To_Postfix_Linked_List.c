#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int stack[MAX];
int n = -1;

int isEmpty(){
	return n == -1;
}


void push(int value){
	stack[++n] = value;
}


int pop(){
	if(isEmpty()){
		printf("Underflow.");
		exit(1);
	}
	int value = stack[n];
	n--;
	return value;
}


struct postfix {
	char symbol[10];
	struct postfix *next;
};


struct postfix *getData(char *symbol){
	struct postfix *temp;
	temp = (struct postfix *)malloc(sizeof(struct postfix));
	for(int i = 1 ; i <= symbol[0] ; i++)
		temp->symbol[i-1] = symbol[i];
	temp->symbol[symbol[0]] = '\0';
	return temp;
}


struct postfix *enqueue(struct postfix *InFix, char *symbol){
	struct postfix *temp, *traversal = InFix;
	temp = getData(symbol);
	if(InFix == NULL){
		temp->next = NULL;
		InFix = temp;
	}
	else{
		while(traversal->next != NULL)
			traversal = traversal->next;
		temp->next = NULL;
		traversal->next = temp;
	}
	return InFix;
}

struct postfix *en(struct postfix *PostFix, char *symbol){
	struct postfix *temp, *traversal = PostFix;
	temp = (struct postfix *)malloc(sizeof(struct postfix));
	int i = 0, count = 0;
	while(symbol[i] != '\0'){
		temp->symbol[i] = symbol[i];
		i++;
		count++;
	}
	temp->symbol[count] = '\0';
	if(PostFix == NULL){
		temp->next = NULL;
		PostFix = temp;
	}
	else{
		while(traversal->next != NULL)
			traversal = traversal->next;
		temp->next = NULL;
		traversal->next = temp;
	}
	return PostFix;
}


void queueDisplay(struct postfix *head){
	struct postfix *temp = head;
	while(temp != NULL){
		printf("%s ", temp->symbol);
		temp = temp->next;
	}
	printf("\n");
}

int opcheck(char value){
	switch(value){
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':
	case '(':
	case ')':
		return 1;
	default:
		return 0;
	}
}

struct postfix *convertToWholeValues(struct postfix *Infix, char *input){
	int power = 1, value = 0, length = 0, k = 0, i = 0;
	while(i < strlen(input)){
		length = 0, k = 1;
		char temp[10];
		if(!opcheck(input[i]) && i < strlen(input)){
			while(!opcheck(input[i]) && i < strlen(input)){
				temp[k++] = input[i++];
				length++;
			}
			temp[0] = length;
			temp[k] = '\0';
			Infix = enqueue(Infix, temp);
		}else{
			temp[0] = 1;
			temp[1] = input[i];
			temp[2] = '\0';
			i++;
			Infix = enqueue(Infix, temp);
		}
	}
	return Infix;
}

int precedence(char symbol){
	switch(symbol){
	case '^':
		return 3;
	case '/':
	case '*':
		return 2;
	case '+':
	case '-':
		return 1;
	default:
		return 0;
	}
}


struct postfix *inToPost(struct postfix *Infix, struct postfix *PostFix){
	int i = 1, j = 0;
	char symbol[10], next;
	struct postfix *temp = Infix;
	struct postfix *post = PostFix;
	while(temp != NULL){
		if(strlen(temp->symbol) == 1){
			if(opcheck(temp->symbol[0])){
			switch(temp->symbol[0]){
			case '(':
				push(temp->symbol[0]);
				temp = temp->next;
				break;

			case ')':
				char temp1[10];
				while((next = pop()) != '('){
					temp1[0] = 1;
					temp1[1] = next;
					temp1[2] = '\0';
					post = enqueue(post, temp1);
				}
				temp = temp->next;
				break;

			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
				while(!isEmpty() ? (precedence(stack[n]) >= precedence(temp->symbol[0])) : 0){
					char temp1[3];
					temp1[0] = 1;
					temp1[1] = pop();
					temp1[2] = '\0';
					post = enqueue(post, temp1);
				}
				push(temp->symbol[0]);
				temp = temp->next;
				break;

			default:
				char temp2[3];
				temp2[0] = 1;
				temp2[1] = temp->symbol[0];
				temp2[2] = '\0';
				post = enqueue(post, temp2);
				temp = temp->next;
			}
		}
		else{
			post = en(post, temp->symbol);
			temp = temp->next;
		}
	}
	else{
		post = en(post, temp->symbol);
		temp = temp->next;
	}
	}
	while(!isEmpty()){
		char temp1[3];
		temp1[0] = 1;
		temp1[1] = pop();
		temp1[2] = '\0';
		post = enqueue(post, temp1);
	}
	return post;
}


int main(){
	struct postfix *InFix = NULL;
	struct postfix *PostFix = NULL;
	struct stack *Stack = NULL;
	char input[100];
	printf("\nEnter the Expression : ");
	gets(input);
	InFix = convertToWholeValues(InFix, input);
	printf("\nInfix Data : ");
	queueDisplay(InFix);
	PostFix = inToPost(InFix, PostFix);
	printf("\nPostFix Data : ");
	queueDisplay(PostFix);
}