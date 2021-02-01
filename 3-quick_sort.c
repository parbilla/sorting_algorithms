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
	int len = (int)size, pivot = array[len - 1], low = 0, i = -1, j = 0, tmp = 0;

	for (j = low; j <= len - 2; j++)
	{
		printf("j: %i, low: %i\n", j, low);
		if (array[j] <= pivot)
		{
			printf("j: %i, low: %i\n", j, low);
			i++;
			printf("array[j]: %i, pivot: %i\n", array[j], pivot);
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
	printf("array[i + 1]: %i, array[len]: %i\n", array[i + 1], array[len]);
	tmp = array[i + 1];
	array[i + 1] = array[len - 1];
	array[len] = tmp;
	print_array(array, size);
}
