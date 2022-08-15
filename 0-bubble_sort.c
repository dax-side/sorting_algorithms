#include "sort.h"

/**
*bubble_sort - function that sorts an array of integers in ascending order
*using the Bubble sort algorithm
*@array: Array of number to sort.
*@size: Size of the array.
*Return: Void.
*/

void bubble_sort(int *array, size_t size)
{
	unsigned int i;
	int swap, flag = 1;

	if (!array || !size || size == 1)
	{
		return;
	}
	while (flag)
	{
		flag = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				swap = array[i - 1];
				array[i - 1] = array[i];
				array[i] = swap;
				flag = 1;
				print_array(array, size);
			}
		}
		if (flag == 0)
			break;
	}
}
