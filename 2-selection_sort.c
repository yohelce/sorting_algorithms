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
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (min != i)
		{
			_swap(&array[min], &array[i]);
			print_array(array, size);
		}
	}
}
