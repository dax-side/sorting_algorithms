#ifndef SORT_H
#define SORT_H

/* libraries */

#include <stdio.h>
#include <stdlib.h>

/* Structures */
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Prototypes */

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap_head(listint_t **list, listint_t *aux);
void swap_middle(listint_t *aux);
void swap_tail(listint_t *aux);
int partition(int *array, int low, int high, size_t size);
void quick(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void evaluate_swap(listint_t **list, listint_t *aux);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void top_downsplit(int *array, size_t begin, size_t end, int *copy);
void td_merge(int *array, size_t begin, size_t middle, size_t end, int *copy);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
int find_maxvalue(int *array, size_t size);
int **malloc_(size_t copies, size_t size);
void array_copy(int *source, int *destiny, size_t size);
void bitonic_sort(int *array, size_t size);
void sort_(int *array, size_t low, size_t size, size_t dir, size_t length);
void merge(int *array, size_t low, size_t size, size_t dir);
void swap(int *array, size_t i, size_t j, size_t dir);

#endif
