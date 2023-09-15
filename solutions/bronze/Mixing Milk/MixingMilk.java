import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;


public class MixingMilk {
    public static void main(String[] args){

        //two arrays
        int capacities[] = new int[3];
        int amounts[] = new int[3];

        //get input
        try {
            File myObj = new File("mixmilk.in");
            Scanner myReader = new Scanner(myObj);
            for(int i=0; i < 3; i++){
                capacities[i] = myReader.nextInt();
                amounts[i] = myReader.nextInt();
            }
        myReader.close();
        } catch (Exception e) {
        }


        //repeat 100 times
        for(int i = 0; i < 100; i++){

            //figure out the buckets
            int index = i % 3;
            int nextIndex = (i + 1) % 3;

            int amt = Math.min(amounts[index], capacities[nextIndex] - amounts[nextIndex]);
            amounts[index] -= amt;
            amounts[nextIndex] += amt;
        }

        try {
            FileWriter myWriter = new FileWriter("mixmilk.out");
            myWriter.write(amounts[0] + "\n" + amounts[1] + "\n" + amounts[2]);
            myWriter.close();
        } catch (Exception e) {
            
        }

    }
}
