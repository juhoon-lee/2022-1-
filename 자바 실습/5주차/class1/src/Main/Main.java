package Main;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // 클래스 예제
        IXServer server = new IXServer();
        IXServer server2 = new IXServer();
        server.printHostServer();

        // 객체별 indentifier
        System.out.printf("%x", System.identityHashCode(server));
        System.out.println();
        System.out.printf("%x", System.identityHashCode(server2));
        System.out.println();

        // ------------------------------------------------------------
        // 사각형 넓이 클래스 만들기
        Scanner scanner = new Scanner(System.in);
        Rectangle rect = new Rectangle();

//        rect.width = scanner.nextInt();
//        rect.height = scanner.nextInt();

        System.out.println(rect.getArea());

        // ------------------------------------------------------------
        // 환율 계산기 예제
        System.out.print("환율(1달러) >> ");
        double rate = scanner.nextDouble();
        CurrencyConverter.setRate(rate);
        System.out.println("$100는 " + CurrencyConverter.toKWR(100) + "원입니다.");
        scanner.close();
    }
}
