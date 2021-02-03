#include "sort.h"

void merge_arrays(int *array, int prin, int mit, int fin)
{
	int i, j, k, n1 = mit - prin + 1, n2 = fin - mit;
	int L[100], R[100];

        /* Copy data to temp array*/
	for (i = 0; i < n1; i++)
		L[i] = array[prin + i];
	for (j = 0; j < n2; j++)
		R[j] = array[mit + 1 + j];
        /* Merge the temp arrays*/
	i = 0;
	j = 0;
	k = prin;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
		k++;
	}
        /* Copy the remaining elements of L[]*/
	while (i < n1)
	{
		array[k] = L[i];
		i++;
		k++;
	}
        /* Copy the remaining elements of R[]*/
	while (j < n2)
	{
		array[k] = R[j];
		j++;
		k++;
	}
}

void merge_recursion(int *array, int prin, int fin)
{
        int mit;

        if (prin >= fin)
                return;
        mit = (fin + prin - 1) / 2;
        merge_recursion(&array[prin], prin, mit);
        merge_recursion(&array[mit + 1], mit + 1, fin);
        merge_arrays(array, prin, mit, fin);
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
void merge_sort(int *array, size_t size)
{
        int fin = (int)size - 1, prin = 0;

        if (array == NULL || size < 2)
                return;

        merge_recursion(&array[prin], prin, fin);
}
