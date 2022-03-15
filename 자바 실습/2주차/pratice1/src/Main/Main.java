package Main;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        System.out.println("이름, 나이를 빈칸으로 분리하여 입력하세요.");

        Scanner scanner = new Scanner(System.in);
        String name = scanner.next();
        int age = scanner.nextInt();

        System.out.println("이름은: " + name + " 나이는: " + age + "입니다.");
    }
}
