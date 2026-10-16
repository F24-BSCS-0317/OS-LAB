#include"stdio.h"

int main(){
	int arr[15];
	int size = 0;
	
	printf("Enter an array of 15 elements: ");
	for(int i = 0; i < 15; i++){
		scanf("%d", &arr[i]);
		size++;
		if(arr[i] == -1){
			size--;
			break;
		}
	}
	
	printf("Input Sequence: ");
	for(int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	
	printf("Updated Sequence: ");
	for(int i = 0; i < size; i++){
		int max = i;
		for (int j = i + 1;j < size; j++){
			if(arr[j] > arr[max]){
				max = j;
			}
		}
		if (arr[max] > arr[i]){
			int temp = arr[max];
			arr[max] = arr[i];
			arr[i] = temp;
		}
	}
	
	for(int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	
	printf("\n");
	return 0;
}
