public class LCS_DP {

    static void lcs(char[] str1, char[] str2) {
        int res = lcs_init(str1,str2, str1.length, str2.length);
        System.out.printf("El string comun mas largo es de %s caracteres", res);
    }

    static int lcs_init(char[] str1, char[] str2, int m, int n){
        if(m==0 || n == 0) {
            return 0;           //El array no tiene elementos
        }if(str1[m-1] == str2[n-1]){
            return 1+lcs_init(str1, str2, m-1, n-1); //si el ultimo elemento es igual compara el siguiente y suma una coincidencia
        }else{
            return Math.max(lcs_init(str1, str2, m, n-1), lcs_init(str1, str2, m-1, n));
        }
    }

    public static void main(String[] args) {
        char[] str1 = {'h','o', 'l', 'a', 'a', 'a'};
        char[] str2 = {'h', 'o', 'l', 'a'};
        lcs(str1, str2);

    }
}
