package week10_collection;

import java.util.ArrayList;
import java.util.Scanner;

public class ArrayList_practice {
    public static void main(String[] args) {
        ArrayList<String> a = new ArrayList<>();

        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < 4 ; i++) {
            System.out.print("이름을 입력하세요 : ");
            String s = scanner.next();
            a.add(s);
        }

        for (int i = 0; i < a.size(); i++) {
            String name = a.get(i);
            System.out.print(name + " ");
        }

        int maxLengthIndex = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a.get(i).length() > a.get(maxLengthIndex).length()) {
                maxLengthIndex = i;
            }
        }
        System.out.println("가장 긴 이름은 : " + a.get(maxLengthIndex));

    }
}
