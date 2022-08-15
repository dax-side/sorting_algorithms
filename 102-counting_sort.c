#include "sort.h"
/**
 * counting_sort - Is a sorting algorithm that sorts the elements
 * of an array by counting the number of occurrences of each unique
 * element in the array. The count is stored in an auxiliary array
 * and the sorting is done by mapping the count as an index of the
 * auxiliary array.
 * @array: Array of data to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	unsigned int i = 1, index = 0, max_ = array[0];
	int *buffer = NULL, *copy;

	if (!array || size < 2)
		return;
	while (i < size)
	{
		if (max_ < (unsigned int)array[i])
			max_ = array[i];
		i++;
	}
	buffer = malloc(sizeof(int) * (++max_));
	i = 0;
	while (i < max_)
		buffer[i] = '\0', i++;
	i = 0;
	while (i < size)
		buffer[array[i]]++, i++;
	i = 1;
	while (i < max_)
		buffer[i] = buffer[i] + buffer[i - 1], i++;
	print_array(buffer, max_);
	i = 0;
	copy = malloc(sizeof(int) * size);
	while (i < size)
	{
		index = --buffer[array[i]];
		copy[index] = array[i];
		i++;
	}
	i = 0;
	while (i < size)
		array[i] = copy[i], i++;

	free(copy);
	free(buffer);
}
