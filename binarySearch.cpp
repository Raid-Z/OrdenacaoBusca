int binarySearch(int value, int *arr, int len) {
	bSearch(arr, 0, len, value);
}

int bSearch(int *array, int start, int end, int value)  {
    if(end >= start){
        int mid = start + (end - start) / 2;
        if (array[mid] == value)
            return mid;

        if(array[mid] > value)
            return binarySearch(array, start, mid - 1, value);

        return binarySearch(array, mid + 1, end, value);
    }
    return -1;
}