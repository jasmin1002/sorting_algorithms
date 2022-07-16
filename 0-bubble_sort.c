#include "sort.h"

/**
  * bubble_sort - Sorts an array of integers in asc order
  *
  * @array: Input array to sort
  * @size: Number of elements in @array
  *
  * Return: nothing
  */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	for(i = 0; i < size - 1; i++)
	{
		int flag = 0;
		size_t new_size = size - 1 - i;

		for(j = 0; j < new_size; j++)
		{
			if (array[j] > array[j + 1])
			{
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;

				flag = 1;
			}
		}

		if (flag == 0)
			break;
	}

	print_array(array, size);
}
