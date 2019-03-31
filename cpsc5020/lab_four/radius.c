/*this program calculates teh area of a circle */
#include <stdio.h>
int main(){
	float radius = 50, area;
	area = 3.14159 * radius * radius;
	if (area > 100)
		printf("The area, %f, is too large. \n", area);
	else
		printf("The area, %f, is within limits. \n", area);
}
