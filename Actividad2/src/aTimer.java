public class aTimer {
    public static void main(String[] args) {
        long startTime = System.nanoTime();
        int min = 1;
        int max = 1000;
        int[] arr = new int[max];
        int element = max;

        for (int j = 0; j < max; j++) {
            arr[j] = (int) ((Math.random() * ((max - min) + 1)) + min);
        }
        for (int i = 0; i < arr.length; i++) {
            /*for(int x = 0; x < arr.length; x++) {
                if (i != x && arr[i] == element && arr[x] == element) {
                    System.out.printf("Elemento %d encontrado en la posicion %d \n", element, i + 1);
                }
            }*/
            if (arr[i] == element) {
                System.out.printf("Elemento %d encontrado en la posicion %d \n", element, i + 1);
            }
        }
            long finishTime = System.nanoTime() - startTime;
            System.out.println("Nanoseconds: " + finishTime);

    }
}
