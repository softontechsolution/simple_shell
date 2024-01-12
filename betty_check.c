#include "shell.h"

/**
 *_swapnums - swaps the value of two integer
 *@num1: holds the value of the first integer
 *@num2: holds the second value
 *temp: holds temporary value
 *
 * Return: nothing
 */

int _swapnums()
{
	int num1, num2, temp;
	printf("enter a value for num1");
	scanf("%d", &num1);
	printf("\nEnter a value for num2");
	scanf("%d", &num2);

	temp = num2;
	num2 = num1;
	num1 = temp;
	printf("\nAfter Swapping Num1 = %d , Num2 = %d", num1,num2);
	return 0;
}
