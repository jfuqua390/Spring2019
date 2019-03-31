#include <stdio.h>

	int main(){
		int count, sq;
		for (count = 1; count < 11; count++)
		{
			sq = square(count);
			printf("The square of %d is %d \n", count, sq);
		}
}
