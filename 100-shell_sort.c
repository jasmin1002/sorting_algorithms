#include "sort.h"

/**
  * shell_sort - Sorts an array of integers in asc order using Shell sort
  * algorithm, using the Knuth sequence.
  * @array: Array to be sorted
  * @size: Length of the given array
  *
  * Return: void (nothing)
  */
void shell_sort(int *array, size_t size)
{
	unsigned int i, j, gap;
	int insert_value;

	if (!array || size < 2)
		return;

	/* Use Knuth sequence for gaps. Reach the biggest gap possible.*/
	for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
		;

	/* First loop to decrement gap after comparisons and swapping.*/
	while (gap > 0)
	{
		/* Second loop to tranverse array with gaps*/
		for (i = gap; i < size; i++)
		{
			/* Set gap value in array as insert value to be inserted.*/
			insert_value = array[i];

			/*
			* Third loop to check elements to shift towards right
			* and compare with [0 ... insert_value]. In case insert value is smaller
			* than integer at smaller position, then swap integer at j.
			*/
			for (j = i; j >= gap && insert_value < array[j - gap]; j -= gap)
				array[j] = array[j - gap];

			/*
			* Insert value at the last position of j.
			* (The smaller position of the gap).
			*/
			array[j] = insert_value;
		}
		/* Decrease gap and print array. */
		gap /= 3;
		print_array(array, size);
	}
}
