#include<stdio.h>
static int capacity = 5;
int *arr = (int *)malloc(capacity * (sizeof(int)));
int n = 0;

void expandArray(){
    capacity *= 2;
    arr = (int *)realloc(arr, capacity * sizeof(int));
}

void shrinkArray(){
    capacity /= 2;
    arr = (int *)realloc(arr, capacity * sizeof(int));
}

void display(){
    for(int i = 0 ; i < n ; i++)
        printf("%d ", arr[i]);
}

void addbeg(int value){
    if(n == capacity)
        expandArray();
    else{
        for(int i = n - 1 ; i >= 0 ; i--)
        arr[i+1] = arr[i];
    arr[0] = value;
    n++;
    }
}

void addPos(int value, int pos){
    if(pos > n)
        printf("\nPlease Enter Valid Position.\n");
    if(n == capacity)
        expandArray();
    else{
        for(int i = n - 1 ; i >= pos ; i--)
            arr[i + 1] = arr[i];
        arr[pos] = value;
        n++;
    }
}

void addend(int value){
    if(n == capacity)
        expandArray();
    else{
        arr[n] = value;
        n++;
    }
}

void delBeg(){
    if(n == 0)
        printf("\nArray is Already Empty.\n");
    if(capacity > (3 * n))
        shrinkArray();
    else{
        for(int i = 0 ; i < n ; i++)
            arr[i] = arr[i + 1];
        n--;
    }
}

void delPos(int pos){
    if(n == 0){
        printf("\nArray is Already Empty.\n");
    }
    if(capacity > (3 * n))
        shrinkArray();
    else if(pos > n){
        printf("\nPlease Enter Valid Position.\n");
    }
    else{
        for(int i = pos ; i < n ; i++)
            arr[i] = arr[i + 1];
        n--;
    }
}

void delEnd(){
    if(n == 0)
        printf("\nArray is Already Empty.\n");
    if(capacity > (3 * n))
        shrinkArray();
    else{
        n--;
    }
}

int isEmpty(){
    return n == 0;
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
    quick(arr, 0, n - 1);
}