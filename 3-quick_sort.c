#include "sort.h"

/**
 * _swap - swap between 2 pointers of int
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
 * partition - divides an array into two partitions
 * @array: array of integers
 * @low: lowest index of the array
 * @high: highest index of the array
 * @size: size of the array
 *
 * Return: pivot index
 */

int partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot;

	/*chose the last element as the pivot*/
	pivot = array[high];
	/*we start in -1*/
	i = low - 1;
	/*iteration from low to high - 1 */
	for (j = low; j <= high - 1; j++)
	{
		/*array[j] must to be less than pivot for swap*/
		if (array[j] < pivot)
		{
			i++; /*i grows plus 1 in each iteration*/
			if (array[i] != array[j])
			{
				_swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	/*if pivot is different than the low array index*/
	if (array[i + 1] != pivot)
	{
		_swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * qs_recursive - Sorts s portion of an array, divides ir into partitions, then
 * sorts those
 * @array: array of integers
 * @low: lowest index of the array
 * @high: highest index of the array
 * @size: size of the array
 *
 * Return: void
 */

void qs_recursive(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		/*Partititon array & get the pivot index*/
		p = partition(array, low, high, size);
		/*sort the two partitions*/
		qs_recursive(array, low, p - 1, size); /*left side of pivot*/
		qs_recursive(array, p + 1, high, size); /*right side of pivot*/
	}
}

/**
 * quick_sort -  sorts an array of integers in ascending order using
 * the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	qs_recursive(array, 0, size - 1, size);
}
