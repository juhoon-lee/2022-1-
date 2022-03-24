package Main;

import java.util.Arrays;

public class Main {

    // 동적으로 배열 생성 후 리턴
    static int[] makeArray(){
        int [] tmp = new int[5];
        for (int i = 0 ; i <tmp.length; i++)
        {
            tmp[i] = i;
        }
        return tmp;
    }

    public static void main(String[] args) {
//        // 비 정방형 배열 만들기
//        int[][] arr = new int[4][];
//        arr[0] = new int[3];
//        arr[1] = new int[2];
//        arr[2] = new int[3];
//        arr[3] = new int[2];
//
//        for (int i = 0; i < arr.length; i++){
//            for (int j = 0; j < arr[i].length; j++){
//                arr[i][j] = (i+1)*10 + j;
//            }
//        }
//
//        for (int i = 0; i < arr.length; i++){
//            for (int j = 0; j < arr[i].length; j++){
//                System.out.print(arr[i][j] + " ");
//            }
//            System.out.println();
//        }


        // 동적 배열
        int[] a = makeArray();
        for (int e: a){
            System.out.println(e);
        }
    }
}
