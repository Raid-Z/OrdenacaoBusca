void bubbleSort(int *arr, int len)
{
	int s=0;
    int temp = 0;
    do{
        s=0;
        for(int i=0;i<len;i++){
            if(arr[i]>arr[i+1]){
                temp = arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                s++;
            }
        }
    }while(s>0);
}
