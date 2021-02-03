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
	int n = (int)size;

	if (array == NULL || size < 2)
		return;
	merge_recursion(array, n);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge sort algorithm
 *
 * @array: Pointer to array
 * @size: length of the array
 *
 * Return: Nothing
 */
void merge_recursion(int *half, int n)
{
	int m = n / 2, index = 0;
	int *left = NULL, *right = NULL;

	printf("entre en el merge\n");
	if (n == 1)
		return;

	if (m % 2 == 0)
	{
		printf("entre en el m  2 = 0\n");
		left = malloc((sizeof(int)) * n + 1);
		printf("malloc m2 = 0 left");
		right = malloc((m * sizeof(int)) * m + 1);
		printf("malloc m2 = 0 left");
		if (half == NULL || right == NULL)
			return;
		left = place_elements(half, left, index, m);
		right = place_elements(half, right, m + 1, n);
	       	merge_recursion(left, m);
		merge_recursion(right, m);
	}
	else
	{
		left = malloc(m * sizeof(int) + 1);
		right = malloc(m  + 1 * sizeof(int) + 1);
		if (half == NULL || right == NULL)
			return;
		left = place_elements(half, left, index, m);
		right = place_elements(half, right, m - 1, n);
		merge_recursion(left, m);
		merge_recursion(right, m + 1);
	}
	new_array(half, left, m);
	new_array(right, right, m);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge sort algorithm
 *
 * @array: Pointer to array
 * @size: length of the array
 *
 * Return: Nothing
 */
int *place_elements(int *half, int *new_array, int start, int end)
{
	int i = 0;

	for (i = start; i <= end; i++)
		new_array[i] = half[i];
	return new_array;
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge sort algorithm
 *
 * @array: Pointer to array
 * @size: length of the array
 *
 * Return: Nothing
 */
void new_array(int *half, int *new_array, int m)
{
	int i, tmp;

	for (i = 0; i < m; i++)
	{
		if (new_array[i] > new_array[i + 1])
		{
			tmp = new_array[i + 1];
			new_array[i + 1] = new_array[i];
			new_array[1] = tmp;
		}
		half[i] = new_array[i];
	}
}
