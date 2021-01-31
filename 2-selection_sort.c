#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 *
 * @array: pointer to array.
 * @size: size of the array.
 *
 * Return: Nothing.
 */
void selection_sort(int *array, size_t size)
{
	size_t index1, index2;
	int to_swap, last_position = 0, tmp;

	for (index1 = 0; index1 < size; index1++)
	{
		to_swap = index1;
		for (index2 = index1 + 1; index2 < size; index2++)
		{
			if (array[index2] < array[to_swap])
				to_swap = index2;
		}
		tmp = array[to_swap];
		array[to_swap] = array[last_position];
		array[last_position] = tmp;
		last_position += 1;
		print_array(array, size);
	}
}
