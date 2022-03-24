package Main;

import java.io.FileWriter;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.Objects;
import java.util.Scanner;

public class Main {


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String isAgain = "y";
        StringBuilder gameLog = new StringBuilder("학번: 12181818 이름: 이주훈\n");
        int gameCount = 0; // 몇번째 게임인지

        System.out.print(gameLog);
        while (isAgain.equals("y")) {
            int targetNumber = (int) (Math.random() * 100 + 1); // 타겟 번호
            int tryCount = 0; // 시도 횟수
            int myNumber = 0; // 고른 숫자
            System.out.println("Guess what(1-100)");

            while (targetNumber != myNumber) {
                System.out.print("input> ");
                // 잘못된 값 입력 Exception 처리 - 예외처리 1
                try {
                    myNumber = scanner.nextInt();
                } catch (InputMismatchException e) {
                    System.out.println("정수를 입력하세요.");
                    scanner.next(); // 버퍼에 남은 값 제거 필요
                    continue;
                }

                if (targetNumber > myNumber) System.out.println("UP");
                else if (targetNumber < myNumber) System.out.println("DOWN");
                tryCount++;
            }

            System.out.println("정답!! " + tryCount + "번 만에 맞춤!");
            gameLog.append("게임번호 ").append(gameCount).append(" : 정답 ").append(tryCount).append("번 만에 맞춤\n"); // log.txt에 들어갈 값

            System.out.print("다시하시겠습니까?(y/n) -> ");

            // y나 n이 아니면 다시 입력받기
            while (true) {
                isAgain = scanner.next();
                try {
                    // 만약 y나 n이 입력되지 않았다면 Exception throw - 예외처리 2
                    if ((!Objects.equals(isAgain, "y")) && (!Objects.equals(isAgain, "n"))) {
                        throw new Exception("y나 n을 입력하세요. -> ");
                    } else {
                        break;
                    }
                } catch (Exception e) {
                    System.out.print(e.getMessage()); // Exception Message 출력
                }
            }

            if (isAgain.equals("n")) break; // n이면 게임 종료
            gameCount++; // 게임 카운트 증가
        }

        // log.txt
        try { // FileWrite Exception 처리 - 예외처리 3
            FileWriter fw = new FileWriter("log.txt");
            fw.write(gameLog.toString());
            fw.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        scanner.close();
    }
}
