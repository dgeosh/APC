import java.util.Scanner;
import java.util.Arrays;

public class JustStalling {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int[] cowHeights = new int[n];
        int[] fitHeights = new int[n];
        
        for(int i = 0; i < n; i++){
            cowHeights[i] = scan.nextInt();
        }
        for(int i = 0; i < n; i++){
            int x = scan.nextInt();
            for(int h:cowHeights){
                if (h <= x) fitHeights[i]++; 
            }
        }
        
        Arrays.sort(fitHeights);

        long f = fitHeights[0];
        
        for(int i=1; i<n; i++){
            f *= (fitHeights[i] - i);
        }


        System.out.println(f);

        scan.close();
    }
}
