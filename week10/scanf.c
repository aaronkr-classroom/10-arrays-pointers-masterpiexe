#include<stdio.h>


int main()
{
	int int_data, oct_data,hex_data;
	float float_data;
	char str_data[20];
	char char_data;
	
	printf("enter the following data:\n");
	printf("%%c, %%d,%%o,%%x,%%f,%%s \n");
	scanf_s("%c", &char_data);
	scanf_s("%d %o %x", &int_data, &oct_data, &hex_data);
	scanf_s("%f", &float_data);
	scanf_s("%s", &str_data);
	
	return 0;
}