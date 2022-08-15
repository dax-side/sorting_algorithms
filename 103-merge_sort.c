#include "sort.h"
/**
 * td_merge - Divides input array in two halves,
 * calls itself for the two halves and then merges
 * the two sorted halves. The merge() function is
 * used for merging two halves.
 * @array: Array of data to be sorted
 * @begin: Start of the array
 * @middle: middle of the array
 * @end: end of array
 * @copy: copy of the original array
 */
void td_merge(int *array, size_t begin, size_t middle, size_t end, int *copy)
{
	size_t i = begin, j = middle, k = begin, l = middle, flag = 0;

	printf("Merging...\n");
	printf("[left]: ");
	while (k < middle)
	{
		if (flag)
			printf(", ");
		printf("%i", array[k]), k++, flag = 1;
	}
	printf("\n");
	flag = 0;
	printf("[right]: ");
	while (l < end)
	{
		if (flag)
			printf(", ");
		printf("%i", array[l]), l++, flag = 1;
	}
	printf("\n");
	k = begin;
	while (k < end)
	{
		if (i < middle && (j >= end || array[i] <= array[j]))
			copy[k] = array[i], i++;
		else
			copy[k] = array[j], j++;
		k++;
	}
	printf("[Done]: ");
	k = begin, flag = 0;
	while (k < end)
	{
		if (flag)
			printf(", ");
		printf("%i", copy[k]), k++, flag = 1;
	}
	printf("\n");
}
/**
 * top_downsplit - Divides input array in two halves.
 * with the left array being smaller than the right array
 * @array: Array of data to be sorted
 * @begin: Start of the array
 * @end: end of array
 * @copy: copy of the original array
 */
void top_downsplit(int *array, size_t begin, size_t end, int *copy)
{
	size_t middle = 0;

	if (end - begin <= 1)
		return;
	middle = (begin + end) / 2;
	top_downsplit(copy, begin, middle, array);
	top_downsplit(copy, middle, end, array);
	td_merge(array, begin, middle, end, copy);
}
/**
 * merge_sort - Divides input array in two halves,
 * calls itself for the two halves and then merges
 * the two sorted halves. The merge() function is
 * used for merging two halves.
 * @array: Array of data to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *copy = NULL;
	size_t i = 0;

	if (!array || size < 2)
		return;
	copy = malloc(4 * size);
	if (!copy)
		return;
	while (i < size)
		copy[i] = array[i], i++;
	top_downsplit(array, 0, size, copy);
	i = 0;
	while (i < size)
		array[i] = copy[i], i++;
	free(copy);
}
