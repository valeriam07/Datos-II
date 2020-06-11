public class log_lineal {

    //QUICKSORT

    public void quickSort(int arr[], int begin, int end) {
        if (begin < end) {
            int partitionIndex = partition(arr, begin, end);

            quickSort(arr, begin, partitionIndex-1);
            quickSort(arr, partitionIndex+1, end);
        }
    }
    private int partition(int arr[], int begin, int end) {
        int pivot = arr[end];
        int i = (begin-1);

        for (int j = begin; j < end; j++) {
            if (arr[j] <= pivot) {
                i++;

                int swapTemp = arr[i];
                arr[i] = arr[j];
                arr[j] = swapTemp;
            }
        }

        int swapTemp = arr[i+1];
        arr[i+1] = arr[end];
        arr[end] = swapTemp;

        return i+1;
    }

    public static void main(String[] args) {
        long startTime = System.nanoTime();
        int [] arr = new int [1000];
        int min = 1;
        int max = 1000;
        int begin = 0;
        int end = 0;

        for (int j = 0; j<1000 ; j++){
            arr[j] = (int) ((Math.random() * ((max - min) + 1)) + min);

            if(j==0){
                begin = arr[j];
            }else if(j==max-1){
                end= arr[j];
            }
        }

        log_lineal a = new log_lineal();
        a.quickSort(arr, begin,end);
        long finishTime = System.nanoTime() - startTime;
        System.out.println("Nanoseconds: " + finishTime);
    }

}
