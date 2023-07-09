#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100

char infix[MAX], postfix[MAX];
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

void inToPost(){
	int i, j = 0;
	char symbol, next;
	for(i = 0 ; i < strlen(infix) ; i++){
		symbol = infix[i];
		switch(symbol){
		case '(':
			push(symbol);
			break;

		case ')':
			while((next = pop()) != '(')
				postfix[j++] = next;
			break;

		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			while(!isEmpty() && precedence(stack[n]) >= precedence(symbol)){
				postfix[j++] = pop();
			}
			push(symbol);
			break;
		default:
			postfix[j++] = symbol;
			break;
		}
	}
	while(!isEmpty())
		postfix[j++] = pop();
	postfix[j] = '\0';
}

int main(){
	printf("\nEnter the Expression(only single digits) : ");
	gets(infix);
	inToPost();
	for(int i = 0; i < strlen(postfix) ; i++)
		printf("%c", postfix[i]);
}
