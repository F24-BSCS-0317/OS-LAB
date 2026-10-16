#include"stdio.h"
#include"string.h"

int main(){
	float radius;
	double pi = 3.14159265;
	printf("What is the radius of the circle? ");
	scanf("%f", &radius);
	double area = pi * radius * radius;
	double circumference = 2 * pi * radius;
	
	printf("\nThe Area of the circle is %lf \n", area);
	printf("The Circumference of the circle is %lf \n", circumference);
	
	
	return 0;
}
