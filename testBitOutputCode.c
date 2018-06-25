#include <stdio.h>

int main ()
{
	int input;
	int output;

	while (1)
	{
		printf("Enter a Number\n");
		scanf("%i",&input);
		printf("\n");
		for (int i = 7; i >= 0; i--)
		{	
			output = (((input >> i )) & 1);
			printf("%i", output);
		}
		printf("\n");
	}
}
