#include "sort.h"
/**
 * siftdown - Swaps elements between parents and child
 * @array: Array of data to be sorted
 * @start: Start of the array
 * @end: end of array
 * @size: size of the original array
 */
void siftdown(int *array, size_t start, size_t end, int size)
{
	size_t root = start, swap = 0, lchild = 0;
	int tmp = 0;

	while (root * 2 + 1 <= end)
	{
		lchild = root * 2 + 1;
		swap = root;
		if (array[swap] < array[lchild])
		swap = lchild;
		if (lchild + 1 <= end && array[swap] < array[lchild + 1])
		swap = lchild + 1;
		if (swap != root)
		{
			tmp = array[root];
			array[root] = array[swap];
			array[swap] = tmp;
			root = swap;
			print_array(array, size);
		}
		else
		return;
	}
}
/**
 * heapify - Heapify the root element again so that we have the highest
 * element at root.
 * @array: Array of data to be sorted
 * @size: size of the array
 */
void heapify(int *array, size_t size)
{
	int start = size / 2 - 1;

	while (start >= 0)
	{
		siftdown(array, start, size - 1, size);
		start = start - 1;
	}
}
/**
 * heap_sort - works by visualizing the elements of the array as a special
 * kind of complete binary tree called a heap.
 * @array: Array of data to be sorted
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int tmp = 0;
	size_t last = size - 1;

	if (size < 2)
		return;
	heapify(array, size);
	while (last > 0)
	{
		tmp = array[last];
		array[last] = array[0];
		array[0] = tmp;
		print_array(array, size);
		last = last - 1;
		siftdown(array, 0, last, size);
	}
}
