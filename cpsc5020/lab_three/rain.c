/* rain.c*/
#include <stdio.h>
int main(){
	int rain, total_rain=0;
	for (rain=0; rain< 10; rain++)
	{
		printf("We have had %d inches of rain. \n", rain);
		total_rain = total_rain + rain;
	}
	printf("We have had a total ");
	printf("of %d inches of rain. \n", total_rain);
}
