#include <stdio.h>

int main()
{
	char array[] = {'h', 'e', 'l', 'l', 'o'};
	int length = sizeof(array) / sizeof(array[0]);
	for(int i = 0; i < length; i++)
	{
		printf("%c", array[i]);
	}
	printf("\n");
	return 0;
}
