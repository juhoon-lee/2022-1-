package week10_collection;

import java.util.HashMap;
import java.util.Scanner;

public class MapPractice {
    public static void main(String[] args) {
        HashMap<String,String> dict = new HashMap<>();
        dict.put("map","지도");
        dict.put("school","학교");
        Scanner scanner = new Scanner(System.in);
        String temp;
        while (true) {
            System.out.print("영어 단어를 입력하시오: ");
            temp = scanner.next();
            if (temp.equals("exit")) break;

            System.out.println("단어의 의미는 " + dict.get(temp));
        }
        scanner.close();
    }
}
