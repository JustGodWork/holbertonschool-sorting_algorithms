nclude "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme
 *
 * @array: Array to be sorted
 * @low: Index of the first element of the current partition
 * @high: Index of the last element of the current partition
 * @size: Size of the array
 *
 * Return: The partitioning index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int tmp;
    int i = low - 1;
    int j;

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;

            if (i != j)
                print_array(array, size);
        }
    }

    tmp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = tmp;

    if (i + 1 != j)
        print_array(array, size);

    return (i + 1);
}

/**
 * quicksort_recursive - Recursive function to perform Quick sort
 *
 * @array: Array to be sorted
 * @low: Index of the first element of the current partition
 * @high: Index of the last element of the current partition
 * @size: Size of the array
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int partition_index = lomuto_partition(array, low, high, size);

        quicksort_recursive(array, low, partition_index - 1, size);
        quicksort_recursive(array, partition_index + 1, high, size);
    }
}

/**
 * quick_sort - Sort an array of integers in ascending order
 *
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort_recursive(array, 0, size - 1, size);
}
