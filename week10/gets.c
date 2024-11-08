#include<stdio.h>
#define MAX_CHAR 50
int main()
{
	char input_str[MAX_CHAR];

	printf("enter ur Engname: ");

	//gets(input_str);
	fgets(input_str, MAX_CHAR,stdin);

		printf("nmae: %s", input_str);

	return 0;
}

