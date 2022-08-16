#include "sort.h"
/**
 * swap - swaps elements of the array checking the position
 * @array: Array with numbers to be sorted
 * @i: position
 * @j: position
 * @dir: 1 if is ascending
 */
void swap(int *array, size_t i, size_t j, size_t dir)
{
	int tmp = 0;

	if (dir == (array[i] > array[j]))
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}
/**
 * merge - swaps elements of the array
 * @array: Array with numbers to be sorted
 * @low: Starting point of the lower part of the array
 * @size: size of the new partition
 * @dir: 1 if is ascending
 */
void merge(int *array, size_t low, size_t size, size_t dir)
{
	size_t k = 0, i = 0;

	if (size > 1)
	{
		k = size / 2;
		i = low;
		while (i < low + k)
			swap(array, i, i + k, dir), i++;
		merge(array, low, k, dir);
		merge(array, low + k, k, dir);
	}
}
/**
 * sort_ - Sorts the array using recursion
 * @array: Array with numbers to be sorted
 * @low: Starting point of the lower part of the array
 * @size: size of the new partition
 * @dir: 1 if is ascending
 * @length: size of the original array
 */
void sort_(int *array, size_t low, size_t size, size_t dir, size_t length)
{
	size_t k = 0;
	int *aux = NULL;

	if (size > 1)
	{
		k = size / 2;
		if (k > 1)
		{
			printf("Merging [%li/%li] (UP):\n", k, length);
			aux = &array[low];
			print_array(aux, k);
		}
		sort_(array, low, k, 1, length);
		if (k > 1)
		{
			printf("Result [%li/%li] (UP):\n", k, length);
			print_array(aux, k);
			printf("Merging [%li/%li] (DOWN):\n", k, length);
			aux = &array[low + k];
			print_array(aux, k);
		}
		sort_(array, low + k, k, 0, length);
		if (k > 1)
		{
			printf("Result [%li/%li] (DOWN):\n", k, length);
			print_array(aux, k);
		}
		merge(array, low, size, dir);
	}
}
/**
 * bitonic_sort - Bitonic sort is a comparison-based sorting algorithm
 * that can be run in parallel. It focuses on converting a random sequence
 * of numbers into a bitonic sequence, one that monotonically increases, then
 * decreases. Rotations of a bitonic sequence are also bitonic.
 * @array: Array of data to be sorted
 * @size: size of the original array
 */
void bitonic_sort(int *array, size_t size)
{
	size_t i = 1;

	while (i < size)
		i <<= 1;
	if (size < 2 || (i ^ size) != 0)
		return;
	printf("Mergin [%li/%li] (UP):\n", size, size);
	print_array(array, size);
	sort_(array, 0, size, 1, size);
	printf("Result [%li/%li] (UP):\n", size, size);
	print_array(array, size);
}
