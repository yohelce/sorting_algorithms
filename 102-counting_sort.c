#include "sort.h"

/**
 * max_value - returns the maximum value of the array
 * @array: array to be parse
 * @size: size of the array
 *
 * Return: max value
 */

int max_value(int *array, size_t size)
{
	int i, max;

	max = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}


void counting_sort(int *array, size_t size)
{
	int i, max, *count_arr, *output_arr;

	if (array == NULL || size < 2)
		return;
	/* Finding the max value */
	max =  max_value(array, size);
	/* Making an array of counter to each value */
	count_arr = malloc(sizeof(size_t) * (max + 1));
	if (!count_arr)
		return;
	/* Adding zeros in the count array */
	for (i = 0; i < (max + 1); i++)
		count_arr[i] = 0;
	/* Adding +1 in the index(value array) into the array of counter for */
	for (i = 0; i < (int)size; i++)
		count_arr[array[i]] += 1;
	/* Adding the value of the matrix to each following matrix up to maximum */
	for (i = 0; i < max; i++)
		count_arr[i + 1] += count_arr[i];
	print_array(count_arr, max + 1);
	/* Making the array of output */
	output_arr = malloc(sizeof(size_t) * size);
	/* If output_arr doesn`t exists we freed count_arr and return */
	if (!output_arr)
	{
		free(count_arr);
		return;
	}
	/* Searching the array value into the count_arr, then returns */
	/* the value -1 and this is the index in the output array */
	for (i = ((int)size - 1); i >= 0; i--)
	{
		count_arr[array[i]] -= 1;
		output_arr[count_arr[array[i]]] = array[i];
	}
	/* Assigning to each value of the array the value of the output array */
	for (i = 0; i < (int)size; i++)
		array[i] = output_arr[i];
	/* Realising the arrays made with malloc*/
	free(count_arr);
	free(output_arr);
}
