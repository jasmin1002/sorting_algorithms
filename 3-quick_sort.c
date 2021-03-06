#include "sort.h"

/**
  * quick_sort - Sorts an array of integers in ascending order
  *
  * @array: Array of integers to sort
  * @size: Size or length of the given array
  *
  * Return: void(nothing)
  */
void quick_sort(int *array, size_t size)
{
	/*
	* QuickSort function that takes first and last index in the array
	*/
	QuickSort(array, 0, size - 1, size);
}

/**
  * QuickSort - Utility function for sorting
  * @array: Array to sort
  * @first: First element
  * @last: Last element
  * @size: Size of the given array
  *
  * Return: void (nothing)
  */
void QuickSort(int *array, int first, int last, size_t size)
{
	int p_index;
	/*
	* first and last index condition, first increases in every subpart
	* and last decreaces in every subpart until the subpart is just one element
	*/
	if (first >= last)
		return;

	/*
	* Function that return the partioning point in the array
	*/
	p_index = partition(array, first, last, size);

	/*
	* Recursion, Sort the elements on the left of pivot
	*/
	QuickSort(array, first, p_index - 1, size);

	/*
	* Recursion, Sort the elements on the right of pivot
	*/
	QuickSort(array, p_index + 1, last, size);
}
/**
 * partition - function that parts the elements in the array
 * @array: array of integers
 * @first: first index in the array
 * @last: last element in the array.
 * @size: size of the array
 * Return: smallest index.
 **/
int partition(int *array, int first, int last, size_t size)
{
	int i, tmp, j, pivot;

	/*
	* pivot is the last element of the array and i the smallest index.
	* i start at 0.
	*/
	pivot = array[last];
	i = first;

	/*
	* transverse the elements of the array, but don't reach the pivot
	*/
	for (j = first; j <= last - 1; j++)
	{
		/*
		* Compare each element of the array with the pivot and swap them
		* at left of the array in case they are smaller (i) than the pivot
		* do nothing if they are greater.
		*/
		if (array[j] <= pivot)
		{
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
			if (i != j)
				print_array(array, size);
			i++;
		}
	}
	/*
	* Take the pivot and place it at the last smallest index (i)
	* return this smallest index that is the partition point of array.
	*/
	tmp = array[j];
	array[j] = array[i];
	array[i] = tmp;
	if (i != j)
		print_array(array, size);
	return (i);
}
