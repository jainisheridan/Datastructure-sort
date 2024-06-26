#include <stdio.h>

int main()
{
	int num;
	printf("Please enter an integer: ");
	scanf("%d", &num);
	num %= 3;

	switch (num) {
		case 0:
			printf("In case 0...\n");
			break;
		
		case 1:
			printf("In case 1...\n");
			break;

		case 2:
			printf("In case 2...\n");
			break;

		}
		return 0;
}
