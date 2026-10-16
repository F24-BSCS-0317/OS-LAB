#include"stdio.h"
#include"stdlib.h"
#include"limits.h"

int main(){
	int size;
	printf("Enter size of array: ");
	scanf("%d", &size);
	int* arr = (int*) malloc(size * sizeof(int));
	for(int i = 0; i < size; i++){
		scanf("%d", &arr[i]);
	}
	int max = INT_MIN;
	int max2 = max;
	for(int i = 0; i < size; i++){
		if(arr[i] > max){
			max2 = max;
			max = arr[i];
		}
		if(arr[i] > max2 && arr[i] < max){
			max2 = arr[i];
		}
	}
	
	printf("Output: %d", max2);
	printf("\n");
	return 0;
}
