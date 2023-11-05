#include<stdio.h>

void reverseString(char* arr, int n) {
	int start = 0, end = n - 1;
	while(start <= end) {
		char temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}

int main() {
	char arr[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
	int len = sizeof(arr)/sizeof(arr[0]);
	reverseString(arr, len);
	for(int i = 0 ; i < len ; i++) {
		printf("%c", arr[i]);
	}
}