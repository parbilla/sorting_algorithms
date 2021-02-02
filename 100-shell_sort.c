#include "sort.h"

/**
 * shell_sort - function that sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence.
 *
 * @array: pointer to array of numbers.
 * @size: number of elements in the array.
 *
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	int left, right, knuth, aux, flag;

	if (array == NULL || size < 2)
		return;

	knuth = 1;
	while (knuth <= (int)size / 3)
	{
		knuth = knuth * 3 + 1;
	}

	while (knuth > 0)
	{
		flag = 1;
		for (left = 0; left < (int)size - knuth; left++)
		{
			right = left + knuth;
			if (array[left] > array[right])
			{
				aux = array[left];
				array[left] = array[right];
				array[right] = aux;
				flag = 0;
			}
		}
		if (flag == 1)
		{
			knuth = (knuth - 1) / 3;
			print_array(array, size);
		}
	}
}
