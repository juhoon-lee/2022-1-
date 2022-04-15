package week4;

import java.util.InputMismatchException;
import java.util.Scanner;

public class DivideZero {
    static int divide(int a, int b) { // try 선택 지점 1
        int tmp = a/b;
        return tmp;
    }

    public static void main(String[] args) {
        int dividend;
        int divisor;
        int result = 0;
        System.out.println("두 정수를 입력하세요.");
        Scanner scanner = new Scanner(System.in);

        // 예외처리
        try{
            dividend = scanner.nextInt();
            divisor = scanner.nextInt();
            result = divide(dividend,divisor); // try 선택 지점 2
        }
        // 구체적인 오류 특정
        catch (ArithmeticException e) { // 예외가 떴을때 예외를 복붙
//            e.printStackTrace();
            System.out.println(e.getMessage());// ->  / by zero
            System.out.println("0으로 나눌수 없습니다.");
        }
        catch (InputMismatchException e){
            System.out.println(e.getMessage() + " 정수만 입력 가능합니다.");
        }
        // 최상위 Exception 객체
        catch (Exception e) {
            System.out.println(e.getMessage());// ->  / by zero
            System.out.println("catch Exception");
        }
        finally {
            System.out.println("finally");
        }

        scanner.close();
        System.out.println("결과: " + result);
    }
}
