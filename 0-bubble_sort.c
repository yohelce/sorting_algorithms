#include "sort.h"

/**
 * _swap -  swap between 2 pointers of int
 * @a: first pointer
 * @b: second pointer
 *
 * Return: void
 */

void _swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - sorts an array of integer in ascending
 * order using BUble sort algorithm.
 * @array: array of integers.
 * @size: size of numbers sorted.
 *
 * Return: void.
 */

void bubble_sort(int *array, size_t size)
{
	size_t  i = 0, j = 0;

	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 1; j < size; j++)
		{
			if (array[j - 1] > array[j])
			{
				_swap(&array[j - 1], &array[j]);
				print_array(array, size);
			}
		}
	}
}
