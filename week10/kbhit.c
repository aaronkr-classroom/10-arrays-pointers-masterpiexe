#include<stdio.h>
#include<conio.h>

int main()
{
	int ch;
	printf("press any key to see ASCII value(ESC to quit):\n");

	while (1)
	{
		if (_kbhit())
		{
			ch = _getch();

			if (ch == 27)
			{
				printf("ESC pressed! Exiting...");
				break;
			}

			if (ch >= 32 && ch <= 126)
			{
				printf("Key : %c, ASCII : %d\n", ch, ch);

			}

			else 
			{
				printf("ASCII: %d\n", ch);
			}

		}
	}

	return 0;
}