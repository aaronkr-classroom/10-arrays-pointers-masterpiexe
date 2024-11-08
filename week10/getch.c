#include<stdio.h>
#include<conio.h>
int main()
{
	char input_data;
	printf("enter chars('q','Q',or ESC to quit):\n");
	int count = 1;

	while (1)
	{
		if (_kbhit()) 
		{

			input_data = _getch();

			rewind(stdin);
			if (input_data == 'q' || input_data == 'Q' || input_data == 27)
			{
				printf("program quit\n");
				break;
			}
			printf("input %d=%c\n", count, input_data);
			count++;
		}

	}
	
	








	return 0;
}