int bSearch(int *array, int start, int end, int value)
{
    if (end >= start)
    {
        int mid = start + (end - start) / 2;
        if (array[mid] == value)
            return mid;

        if (array[mid] > value)
            return bSearch(array, start, mid - 1, value);

        return bSearch(array, mid + 1, end, value);
    }
    return -1;
}

int binarySearch(int value, int *arr, int len)
{
    bSearch(arr, 0, len, value);
}
