#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge sort algorithm
 *
 * @array: Pointer to array
 * @size: length of the array
 *
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	int n = (int)size, m;
	int *left, *right;

	if (array == NULL || size < 2)
		return;

	m = n / 2;
	if (n % 2 == 0)
	{
	       	merge_recursion(left, m);
		merge_recursion(right, m);
	}
	else
	{
		merge_recursion(left, m);
		merge_recursion(right, m + 1);
	}
}


void merge_recursion(int *half, int m)
{
	if (n == 1)
		return;

	half = malloc(m * sizeof(int));
	if (half == NULL)
		return;

}























	while (n > 0)
	{
		new_n = 0;
		for (i = 0; i < n - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap = array[i];
				array[i] = array[i + 1];
				array[i + 1] = swap;
				new_n = i + 1;
				print_array(array, size);
			}
		}
		n = new_n;
	}
}
