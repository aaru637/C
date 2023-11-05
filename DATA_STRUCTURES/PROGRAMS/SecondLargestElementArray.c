#include<stdio.h>

int secondLargest(int *arr, int n) {
	int firstMax = arr[0], secondMax = -1;
	for(int i = 1 ; i < n ; i++) {
		if(arr[i] > firstMax) {
			secondMax = firstMax;
			firstMax = arr[i];
		}
		else if(arr[i] > secondMax && arr[i] != firstMax) {
			secondMax = arr[i];
		}
	}
	return secondMax;
}

int main() {
	int arr[] = {5, 4, 3, 2, 1};
	int len = sizeof(arr)/sizeof(arr[0]);
	printf("%d ", secondLargest(arr, len));
}