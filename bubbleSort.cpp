void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void bubbleSort(int *arr, int len)
{
	int s = 0;
	int temp = 0;
	do
	{
		s = 0;
		for (int i = 0; i < len; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				s++;
			}
		}
	} while (s > 0);
}
