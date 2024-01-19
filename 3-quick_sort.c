#include "sort.h"

/**
 * partition - Partitions an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: The array to be sorted
 * @start_index: The starting index of the partition
 * @end_index: The ending index of the partition
 * @size: Number of elements in @array
 *
 * Return: The index of the pivot
 */
int partition(int *array, int start_index, int end_index, size_t size)
{
	int pivot = array[end_index];
	int i = start_index - 1, j, tmp;

	for (j = start_index; j < end_index; ++j)
	{
		if (array[j] < pivot)
		{
			++i;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[end_index])
	{
		tmp = array[i + 1];
		array[i + 1] = array[end_index];
		array[end_index] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	int pivot;

	if (array == NULL || size < 2)
		return;

	pivot = partition(array, 0, size - 1, size);
	if (pivot > 0)
		quick_sort(array, pivot);
	if (pivot < (int)size - 1)
		quick_sort(array, size - pivot - 1);
}
