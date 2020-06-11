import java.lang.*;

public class LCS_DandQ {

    static void printMatrix(int[][] matriz, int m){
        for (int x=0; x < matriz.length; x++) {
            System.out.print("|");
            for (int y=0; y < m-1; y++) {
                System.out.print (matriz[x][y]);
                if (y!=matriz[x].length-1) System.out.print("\t");
            }
            System.out.println("|");
        }
    }

    static int lcs(char[] str1, char[] str2){
        int m = str1.length;
        int n = str2.length;
        int [][] L = new int[m+1][n+1];  //matriz de resultados
        int res = 0;
        int posX = 0;
        int posY = 0;

        for (int i = 0; i <= m; i++){
            for(int j=0; j <= n; j++){
                if(i == 0 || j ==0){
                    L[i][j] = 0;
                }else if(str1[i-1] == str2[j-1]){
                    L[i][j] = L[i-1][j-1] +1;
                }
                if(L[i][j] > res){
                    res = L[i][j];
                    posX = i;
                    posY = j;
                }
            }
        }printMatrix(L, m);

        System.out.printf("El string comun mas largo es de: %s y se encuentra en la posicion [%s][%s]", res, posX+1, posY+1);
        return L[m][n];
    }

    public static void main(String[] args) {
        char[] str1 = {'h','o', 'l', 'a', 'a', 'a'};
        char[] str2 = {'h', 'o', 'l', 'a'};
        lcs(str1, str2);
    }



}

