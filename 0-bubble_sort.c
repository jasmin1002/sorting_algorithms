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

	/* Make pass */
	for (i = 0; i < size - 1; i++)
	{
		int flag = 0;
		size_t new_size = size - 1 - i;

		/* Compare the adjacent elements */
		for (j = 0; j < new_size; j++)
		{
			/* Shift the higher integer to far right by swapping */
			if (array[j] > array[j + 1])
			{
				int tmp = array[j];

				array[j] = array[j + 1];
				array[j + 1] = tmp;

				flag = 1;
				print_array(array, size);
			}
		}

		/* Check if subsequent pass is necessary */
		if (flag == 0)
			break;
	}

}
