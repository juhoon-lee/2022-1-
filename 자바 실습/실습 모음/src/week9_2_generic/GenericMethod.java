package week9_2_generic;

import java.util.Arrays;

class MyArray {
    static <T> void swap( T[] arr, int x, int y) { // 제네릭 메서드
        T temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
    }
    static <T> void print(T[] arr) {
//        System.out.println(Arrays.toString(arr));
        for (T e: arr) {
            System.out.print(e + " ");
        }
        System.out.println();
    }
}


public class GenericMethod {
    public static void main(String[] args) {
        // Integer
        Integer[] arr1 = {1,2,3,4,5};
        System.out.println(Arrays.toString(arr1));
        MyArray.swap(arr1,3,4);
        System.out.println(Arrays.toString(arr1));

        // String
        String[] arr2 = {"a","b","c","d","e"};
        System.out.println(Arrays.toString(arr2));
        MyArray.swap(arr2,3,4);
        System.out.println(Arrays.toString(arr2));

        // Generic Print Array
        MyArray.print(arr1);
        MyArray.print(arr2);
    }
}
