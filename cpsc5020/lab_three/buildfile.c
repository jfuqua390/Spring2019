#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *out_file;
	int count = 0;
	char msg[] = "This was created by a C program. \n";
	if((out_file = fopen("testfile", "w")) == NULL)
	{
		printf("Error opening file. \n");
		exit(1);
	}
	while(count < 33)
	{
		fputc(msg[count], out_file);
		count++;
	}
	fclose(out_file);
}
