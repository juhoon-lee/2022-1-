package Main;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        int[] arr = new int[5];
        for (int e: arr) {
            System.out.println(e); // 0 0 0 0 0 -> int의 초기값은 0 이군
        }
        System.out.println(Arrays.toString(arr)); // 배열의 원소를 String으로 한 줄로 출력함


        boolean[] arr2 = new boolean[5];
        for (boolean e : arr2) {
            System.out.println(e); // boolean의 초기값은 false이군
        }
        System.out.println(Arrays.toString(arr2));

        String[] arr3 = new String[5];
        for (String e : arr3) {
            System.out.println(e); // String의 초기값은 null이군
        }
        System.out.println(Arrays.toString(arr3));
    }
}
