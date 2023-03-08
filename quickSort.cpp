int Partition(int arr[], int l, int r){
    int pivot = arr[r];
    int i = l;
    for(int j = l; j<r; j++){
        if(arr[j] <= pivot){
            if(i!=j){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            i++;
        }
    }
    int temp = arr[i];
    arr[i] = arr[r];
    arr[r] = temp;
    return i;
}
void qSort(int arr[], int l, int r){
    if(l<=r){
        int p = Partition(arr, l, r);
        qSort(arr, l, p - 1);
        qSort(arr, p + 1, r);
    }
}
void quickSort(int *arr, int len)
{
	qSort(arr, 0, len);
}
