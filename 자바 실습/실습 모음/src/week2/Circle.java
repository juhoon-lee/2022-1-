package week2;
import java.util.Scanner;

public class Circle {

    final static double PI = 3.121592;
    public static void main(String[] args) {
        System.out.println("radius: ");
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt();
        double area = PI*r*r;

        System.out.println("원의 면적은 " + area + "입니다.");
        sc.close(); // Scanner close 까먹지 않기
    }
}