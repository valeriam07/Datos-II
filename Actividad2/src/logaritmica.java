public class logaritmica {

    //BUSQUEDA BINARIA

    public static int buscar( int [] arreglo, int dato) {
        int inicio = 0;
        int fin = arreglo.length - 1;
        int pos;
        while (inicio <= fin) {
            pos = (inicio+fin) / 2;
            if ( arreglo[pos] == dato )
                return pos;
            else if ( arreglo[pos] < dato ) {
                inicio = pos+1;
            } else {
                fin = pos-1;
            }
        }
        return -1;
    }

    public static void  main (String args[]) {

        long startTime = System.nanoTime();
        int [] arr = new int [1000];
        int min = 1;
        int max = 1000;
        for (int j = 0; j<1000 ; j++){
            //arr[j] = (int) ((Math.random() * ((max - min) + 1)) + min);
            arr[j] = j+1;
        }
        // Mostrar arreglo.
        for (int i = 0; i < arr.length ; i++)
            System.out.println ( "edades["+i+"]: "+  arr[i]);

        int resultado = buscar(arr, 10);

        if (resultado != -1) {
            System.out.println ( "Encontrado en: "+  resultado);
        } else {
            System.out.println ( "El dato no se encuentra en el arreglo, o el arreglo no estÃ¡ ordenado."  );
        }
        long finishTime = System.nanoTime() - startTime;
        System.out.println("Nanoseconds: " + finishTime);

    }
}
