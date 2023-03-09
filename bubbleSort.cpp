void bubbleSort(int *arr, int len)
{
	bool swapped = false;
	while (swapped)
	{
		for (int i = 1; i < len; i++)
		{
			if (arr[i - 1] > arr[i])
			{
				swap(arr[i - 1], arr[i]);
			}
		}
	}
}

void swap(int &a, int &b)
{
	int aux = b;
	b = a;
	a = aux;
}
