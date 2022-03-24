package PrimeNumber;

import java.util.List;
import java.util.Scanner;
import java.lang.Math;
import java.util.ArrayList;

// 르장드르 x / (log(x) - 1)

public class PrimeNumber {
    public static List<Integer> primeNumbers = new ArrayList<Integer>();
    public static int primeCount;

//     소수 구하기 - 개선 전: brute-force 방법
    public static void check_prime(int k) {
        int i;
        for (i = 2; i < k; i++) {
            if (k % i == 0) {
                return;
            }
        }
        primeNumbers.add(k);
        primeCount++;
    }

    // 소수 구하기 - 개선된 방법
    public static void improvementPrimeCheck(int k) {
        int i;
        for (i = 0; i < primeCount; i++) {
            int checkPrime = primeNumbers.get(i);
            if (checkPrime * checkPrime > k ){
                break;
            }
            else if ( k % checkPrime == 0 ) {
                return;
            }
        }
        primeNumbers.add(k);
        primeCount++;
    }

    // 르장드르 값 구하기
    public static void legendreNumber(int n) {
        double legendre = n / (Math.log(n) - 1);
        System.out.print("Legendre: " + String.format("%.0f", legendre) + ", ");
    }

    // 쌍둥이 소수 구하기
    public static void twinPrimes() {
        int twins = 0;
        for (int i = 0; i < primeCount-1; i++){
            if(primeNumbers.get(i + 1) - primeNumbers.get(i) == 2){
                twins++;
            }
        }
        System.out.print("Number of Twin Primes: " + twins + " ");

    }

    public static void main(String[] args) {

        System.out.println("학번: 12181818 이름: 이주훈");

        Scanner scanner = new Scanner(System.in);
        int n;
        while (true) {
            System.out.print("탐색 범위 선택(0입력시종료): ");
            n = scanner.nextInt();
            primeCount = 0;
            primeNumbers.clear();
            if (n < 2) {
                if (n == 0) {
                    break;
                }
                System.out.println("2 이상을 입력하세요(0입력시 종료)");
                continue;
            }

            long sx = System.currentTimeMillis();
            for (int i = 2; i <= n; i++) {

//---------------여기서 선택 ------------------------------------------------------

//                check_prime(i); // 개선 전
                improvementPrimeCheck(i); // 개선 후

//---------------여기서 선택 ------------------------------------------------------


            }
            long ex = System.currentTimeMillis();
            System.out.print("Nums of Primes: " + primeCount + ", "); // 소수의 수
            legendreNumber(n); // 르장드르 수 구하기 및 출력
            twinPrimes(); // 쌍둥이 소수 구하기 및 출력
            System.out.println("(" + (ex - sx) + "ms)");
        }
        scanner.close();
    }
}