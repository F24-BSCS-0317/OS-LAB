#include"stdio.h"

int main(){
	int marks;
	printf("Enter Marks(Out of 100): ");
	scanf("%d", &marks);
	if (marks > 100 || marks < 0){
		printf("Invalid Marks!");
	}
	else if (marks >= 80){
		printf("Grade A");
	}
	else if (marks >= 70 && marks < 80){
		printf("Grade B");
	}
	else if (marks >= 60 && marks < 70){
		printf("Grade C");
	}
	else if (marks >= 50 && marks < 60){
		printf("Grade D");
	}
	else{
		printf("Grade F");
	}
	printf("\n");
	return 0;
}
