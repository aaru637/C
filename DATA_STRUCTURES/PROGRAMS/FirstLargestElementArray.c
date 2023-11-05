#include<stdio.h>

int firstLargestElement(int *arr, int n) {
	int max = arr[0];
	for(int i = 1 ; i < n ; i++) {
		if(arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int len = sizeof(arr)/sizeof(arr[0]);
	printf("%d ", firstLargestElement(arr, len));
}