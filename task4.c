#include"stdio.h"

void ispalindrome(int num){
	int temp = num;
	int temp2 = 0;
	while(temp > 0){
		temp2 += temp%10;
		temp2*=10;
		temp/=10;	
	}
	temp2/=10;
	
	if(temp2 == num){
		printf("Palindrome");
	}
	else{
		printf("Not a Palindrome");
	}

}

int main(){
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);
	ispalindrome(num);
	printf("\n");
	return 0;
}
