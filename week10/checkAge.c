#include<stdio.h>
int main()
{
	int num;
	while (1)
	{
		printf("input age: ");
		
		if (scanf_s("%d", &num) == 0)
		{
			rewind(stdin);
			printf("Enter digit number\n");
		}
		else {
			if(num >= 0 && num <= 130)
			{
				printf("inputed age: %d", num);
				break;
			}
			else
			{
				printf("invalid age\n");
			}
		}
	}
}