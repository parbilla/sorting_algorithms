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
	int to_swap, tmp;

	for (index1 = 0; index1 < size; index1++)
	{
		to_swap = index1;
		for (index2 = index1 + 1; index2 < size; index2++)
		{
			if (array[index2] < array[to_swap])
				to_swap = index2;
		}
		if (to_swap != (int)index1)
		{
			tmp = array[index1];
			array[index1] = array[to_swap];
			array[to_swap] = tmp;
			print_array(array, size);
		}
	}
}
