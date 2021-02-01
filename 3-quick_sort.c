#include "sort.h"

/**
 * quick_sort - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm.
 *
 * @array: pointer to array.
 * @size: size of array.
 *
 * Return: Always 0
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;
	the_really_quicksort(array, 0, (int)size - 1, (int)size);
}

/**
 * the_really_quicksort - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm.
 *
 * @array: pointer to array.
 * @low: low index.
 * @high: high index.
 *
 * Return: Always 0
 */
void the_really_quicksort(int *array, int low, int high, int size)
{
	int p;

	if (low < high)
	{
		p = partition(array, low, high, size);
		the_really_quicksort(array, low, p - 1, size);
		the_really_quicksort(array, p + 1, high, size);
	}
}

/**
 * partition - Lomuto method
 *
 * @array: pointer to array.
 * @low: low index.
 * @high: high index
 *
 * Return: i + 1
 */

int partition(int *array, int low, int high, int size)
{
	int pivot = array[high], i = (low - 1), j = 0, tmp = 0;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (j != i)
			{
				tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
				print_array(array, size);
			}
		}
	}
	tmp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = tmp;
	print_array(array, size);
	return (i + 1);
}
