void qSort(int *arr , int start ,int end ) {
	if (end <= 1) {
		return;
	}
	int pivot = arr[end-1];
	int i = 0;
	for (int j = 0; j < end-1; j++) {
		if (arr[j] <= pivot) {
			arr[i], arr[j] = arr[j], arr[i];
			i++;
		}
	}
	arr[i], arr[end-1] = arr[end-1], arr[i];
	qSort(arr, start, i);
	qSort(arr, i+1, end);
}

void quickSort(int *arr, int len) {
	qSort(arr, 0, len);
}
