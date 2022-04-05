package Main;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
//        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < 10; i++){
            char a = 'a';
            System.out.println((char)(a+i));
        }
        int a [] = {1,2,3,4,5};
        for (int sss: a){
            System.out.println(sss);
        }

        enum A {D,S,A};
        A g[] = A.values();
        System.out.println(g[0]);
//        scanner.close();
    }
}
