package Main;

import java.util.Arrays;

public class Main {

    static void shuffle(int[] arr){
        int n = (int)(Math.random()*10);
        int t = arr[0];
        arr[0] = arr[n];
        arr[n] = t;
    }

    public static void main(String[] args) {
        int[] numArr = {0,1,2,3,4,5,6,7,8,9};
        System.out.println(Arrays.toString(numArr));
        for (int i = 0; i < numArr.length; i++){
            shuffle(numArr);
        }
        System.out.println(Arrays.toString(numArr));
    }
}
