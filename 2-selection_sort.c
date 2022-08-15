#include "sort.h"

/**
*selection_sort - is an in-place comparison sorting algorithm.
*@array: Array of number to sort.
*@size: Size of the array.
*Return: Void function ( Nothing).
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j, min, temp;

	if (size < 2)
	return;
	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min] > array[j])
			min = j;
		}
		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
