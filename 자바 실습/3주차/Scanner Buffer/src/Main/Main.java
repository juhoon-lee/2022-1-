package Main;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        System.out.print("입력하세요 : ");
        int inputInt = scanner.nextInt();
        System.out.println("inputInt = " + inputInt);

        // 해결법
        scanner.nextLine();

        System.out.print("입력하세요 : ");
        String inputString = scanner.nextLine();
        System.out.print("inputInt = " + inputString);
    }
}
