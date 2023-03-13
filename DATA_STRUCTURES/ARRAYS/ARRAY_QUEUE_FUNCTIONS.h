#include<stdio.h>
static int capacity = 5;
int *arr = (int *)malloc(capacity * (sizeof(int)));
int n = -1;

void expandArray(){
	capacity *= 2;
	arr = (int *)realloc(arr, capacity * sizeof(int));
}

void shrinkArray(){
	capacity /= 2;
	arr = (int *)realloc(arr, capacity * sizeof(int));
}

void display(){
	if(n == -1)
		printf("\nStack is Underflow.\n");
	else{
		for(int i = 0 ; i <= n ; i++)
			printf("%d ", arr[i]);
	}
}

void enQueue(int value){
	if(n == capacity - 1){
		expandArray();
	}
	n++;
	arr[n] = value;
}

int deQueue(){
	if(n == -1){
		printf("\nUnderflow.\n");
		return -1;
	}
	else{
	if(capacity > (3 * n))
		shrinkArray();
		int value = arr[0];
		for(int i = 0 ; i <= n ; i++)
			arr[i] = arr[i + 1];
		n--;
		return value;
	}
}

int peek(){
	if(n == -1){
		printf("Stack is Underflow.\n");
		return -1;
	}
	else{
		return arr[n];
	}
}

int isEmpty(){
	return n == -1;
}

int Binarysearch(int value){
    int start = 0 , end = n;
    while(start <= end){
        int mid = (start + end) / 2;
        if(arr[mid] == value){
            return mid + 1;
        }
        else if(arr[mid] < value){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}

int LinearSearch(int value){
    for(int i = 0 ; i < n ; i++){
        if(arr[i] == value){
            return i + 1;
        }
    }
    return -1;
}

void quick(int *arr, int start, int end){
    if(start >= end)
        return;
    int i = start, j = end, mid = (start + end) / 2;
    int pivot = arr[mid];

    while(i <= j){
        while(arr[i] < pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if(i <= j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    quick(arr, start, j);
    quick(arr, i, end);
}

void quickSort(){
    quick(arr, 0, n);
}