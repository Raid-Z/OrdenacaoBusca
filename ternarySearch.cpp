int tSearch(int value, int *arr, int start, int end)
{
	// TODO: Implement me https://www.geeksforgeeks.org/ternary-search/
	if (end >= start)
	{
		int mid1 = start + (end - start) / 3;
		int mid2 = start - (end - start) / 3;
		if (arr[mid1] == value)
			return mid1;

		if (arr[mid1] > value)
			return tSearch(value, arr, start, mid1 - 1);
		if (arr[mid2] > value)
			return tSearch(value, arr, mid1, mid2 - 1);
		return tSearch(value, arr, mid2, end);
	}
	return -1;
}

int ternarySearch(int value, int *arr, int len)
{
	return tSearch(value, arr, 0, len);
}
