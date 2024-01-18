#include "sort.h"
/**
 * swap - function
 * @a: element to be swapped
 * @b: element to be swapped
 * Description: a function that swaps
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *b;
	*b = *a;
	*a = temp;
}
/**
 * partition - function
 * @array: array of integers
 * @start: lower bound
 * @end: upper bound
 * @size: sizer of array
 * Description: a function that divides array into partition
 * Return: int
 */
int partition(int *array, int start, int end, size_t size)
{
	int i = start - 1;
	int j;
	int pivot = array[end];

	for (j = start; j <= end - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
		}

	}
	swap(&array[i + 1], &array[end]);
	if (i + 1 != j)
		print_array(array, size);
	return (i + 1);

}

/**
 * quicksort - function
 * @array: array of integers
 * @start: lower bound
 * @end: upper bound
 * @size: size of array
 * Description: recursive function that sorts
 * Return: void
 */

void quicksort(int *array, int start, int end, size_t size)
{
	int partitionIndex;

	if (start < end)
	{
		partitionIndex = partition(array, start, end, size);
		/*printf("PI = %d\n", partitionIndex);*/
		quicksort(array, start, partitionIndex - 1, size);
		quicksort(array, partitionIndex + 1, end, size);
	}
}

/**
 * quick_sort - function
 * @array: element to be swapped
 * @size: element to be swapped
 * Description: a function that sorts
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	quicksort(array, 0, size - 1, size);
}
